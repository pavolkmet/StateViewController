//
//  ErrorView.m
//  StateableViewController
//
//  Created by Pavol Kmet on 28/06/2017.
//  Copyright © 2017 Pavol Kmet. All rights reserved.
//

#import "ErrorView.h"

@interface ErrorView ()

@property (weak, nonatomic) UIView *view;
@property (weak, nonatomic) IBOutlet UIButton *tryAgainButton;

@end

@implementation ErrorView

- (instancetype)initWithTarget:(id)target action:(SEL)action
{
    self = [super init];
    if (self) {
        [self loadNibFromClass:[self class]];
        [self.tryAgainButton addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    }
    return self;
}

- (void)loadNibFromClass:(Class)aClass
{
    UIView *view = (UIView *)[[UINib nibWithNibName:NSStringFromClass(aClass) bundle:nil] instantiateWithOwner:self options:nil].firstObject;
    if (view) {
        self.view = view;
        self.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
        self.view.autoresizingMask = self.autoresizingMask;
        self.view.frame = self.bounds;
        [self addSubview:self.view];
    }
}

@end
