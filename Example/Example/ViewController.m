//
//  ViewController.m
//  Example
//
//  Created by Pavol Kmeť on 29/06/2017.
//  Copyright © 2017 Pavol Kmeť. All rights reserved.
//

#import "ErrorView.h"
#import "EmptyView.h"
#import "ImageTableViewCell.h"
#import "LoadingView.h"
#import "RequestManager.h"
#import "ViewController.h"
#import <StateViewController/UIViewController+StateViewController.h>

@interface ViewController () <UITableViewDataSource, UITableViewDelegate, StateViewController>

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UISegmentedControl *segmentedControl;

@property (nonatomic) BOOL showError;
@property (nonatomic) BOOL showEmpty;
@property (strong, nonatomic) NSArray<Page *> *pages;

@end

@implementation ViewController

#pragma mark - Lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Frame is not needed because we are using constraints
    self.loadingView = [LoadingView new];
    self.errorView = [[ErrorView alloc] initWithTarget:self action:@selector(sendRequest:)];
    self.emptyView = [EmptyView new];
    
    self.showError = YES;
    [self fetchData];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [self setupInitialState];
}

#pragma mark - IBAction

- (IBAction)segmentedDidChange:(UISegmentedControl *)sender
{
    self.showEmpty = sender.selectedSegmentIndex == 0;
    self.showError = sender.selectedSegmentIndex == 1;
}

- (IBAction)send:(UIBarButtonItem *)sender
{
    self.pages = nil;
    [self.tableView reloadData];
    [self fetchData];
}

#pragma mark - Selector

- (void)sendRequest:(UIButton *)sender
{
    [self showContent];
    [self fetchData];
}

#pragma mark - Table View Data Source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.pages.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    ImageTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ImageTableViewCell" forIndexPath:indexPath];
    
    [cell configureWithPage:self.pages[indexPath.row]];
    
    return cell;
}

#pragma mark - Table View Delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

#pragma mark - State View Controller

- (BOOL)hasContent
{
    return self.pages.count > 0;
}

- (UIEdgeInsets)insetForStateView:(UIView *)stateView
{
    return UIEdgeInsetsZero;
}

- (void)handleErrorWhenContentsAvailable:(NSError *)error
{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Error" message:error.localizedDescription preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil]];
    
    [self presentViewController:alert animated:YES completion:nil];
}

#pragma mark - Fetching

- (void)fetchData
{
    [self startLoadingAnimated:YES completion:nil];
    
    [[RequestManager sharedManager] relatedPagesShowError:self.showError showEmpty:self.showEmpty success:^(NSArray<Page *> *relatedPages) {
        
        self.pages = relatedPages;
        [self.tableView reloadData];
        [self endLoadingAnimated:YES completion:nil];
        
        if (self.showEmpty) {
            [self showContent];
        }
        
    } failure:^(NSError *error) {
        [self endLoadingAnimated:YES error:error completion:nil];
    }];
}

- (void)showContent
{
    self.segmentedControl.selectedSegmentIndex = 2;
    [self segmentedDidChange:self.segmentedControl];
}

@end
