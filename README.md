# StateViewController

[![Version](https://img.shields.io/cocoapods/v/StateViewController.svg?style=flat)](http://cocoapods.org/pods/StateViewController)
[![License](https://img.shields.io/cocoapods/l/StateViewController.svg?style=flat)](http://cocoapods.org/pods/StateViewController)
[![Platform](https://img.shields.io/cocoapods/p/StateViewController.svg?style=flat)](http://cocoapods.org/pods/StateViewController)

A view controller category which presents UIViews for loading, error and empty states.

<p align="center"> 
<img src=Resources/StateViewController-Gif.gif>
</p>

- [Requirements](#requirements)
- [Installation](#installation)
- [Overview](#overview)
- [Usage](#usage)
- [Life cycle](#life-cycle)
- [Author](#author)
- [Inspiration](#inspiration)
- [License](#license)

## Requirements

- iOS 8.0+
- Xcode 7.0+
- Objective-C

## Installation

### Cocoapods

`StateViewController` is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'StateViewController'
```

Then just run `pod install`.

### Manually

Just drag and drop all files from folder `Source` in the `StateViewController` into your project and select `Copy items if needed`.

## Overview

State View Controller allows you to easily manager four most common states:

* **Loading state:** View controller loads data from network. **Loading view** is presented.
* **Error state:** An error occurred while loading data from network. **Error view** is presented.
* **Empty state:** Data has been retrieved, but content is not available. **Empty view** is presented.
* **Content state:** Content is available and it's presented.

## Usage

First make sure that you have imported category.

#### Cocoapods

```objective-c
#import <StateViewController/UIViewController+StateViewController.h>
```

#### Manually

```objective-c
#import "UIViewController+StateViewController.h"
```

Then make sure that your `UIViewController` or `UITableViewController` or `UICollectionViewController` adopts protocol `StateViewController`.

```objective-c
@interface ViewController () <StateViewController>
 // Code
@end
```

Then, configure the `loadingView`, `emptyView` and `errorView` properties in `viewDidLoad`.

```objective-c
- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.loadingView = // Custom loading view type of UIView
    self.errorView = // Custom error view type of UIView
    self.emptyView = // Custom empty view type of UIView
}
```

After that in `viewWillAppear:` method you must call `setupInitialState` method which setup as method name says initial state of view controller.

```objective-c
- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [self setupInitialState];
}
```

After that, simply tell the view controller whenever content is loading and `StateViewController` will take care of showing and hiding the correct loading, error and empty view for you.

```objective-c
- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // After setting loading, error, empty views
    [self fetchData];
}

- (void)fetchData
{
    [self startLoadingAnimated:YES completion:nil];
    
    NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:@"http://example.com"]];
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *task = [session dataTaskWithRequest:request completionHandler: ^(NSData *data, NSURLResponse *response, NSError *error) {
        //
        [self endLoadingAnimated:YES error:error completion:nil];
    }];
    [task resume];
}
```

## Life cycle

`StateViewController` calls the `hasContent` method to check if there is any content to display. If you do not implement this method in your own `UIViewController`, `StateViewController` will always assume that there is no content to display. 

But if your view controller is kind of class `UITableViewController` or `UICollectionViewController`, `StateViewController` in default implementation check if `numberOfSections > 0`.

```objective-c
- (BOOL)hasContent
{
    return self.people.count > 0;
}
```

Also you might also be interested to respond to an error even if content is already shown. `StateViewController` will not show an `errorView` in this case, because there is already content that can be shown.

To e.g. show a custom alert or other error message, use `handleErrorWhenContentsAvailable:` to manually present the error to the user.

```objective-c
- (void)handleErrorWhenContentsAvailable:(NSError *)error
{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Error" message:error.localizedDescription preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil]];
    
    [self presentViewController:alert animated:YES completion:nil];
}
```

If your view (loading, error, empty) should have insets you can implement in you view controller method with name `insetForStateView:` which is called every time before the view is presented.

```objective-c
- (UIEdgeInsets)insetForStateView:(UIView *)stateView
{
    return UIEdgeInsetsZero;
}
```

## Author

Pavol Kmet

- Email: [pavol.kmet@goodrequest.com](mailto:pavol.kmet@goodrequest.com)
- Twitter: [@PavolKmet](https://twitter.com/PavolKmet)

## Inspiration

This pod takes inspiration from Swift version of [StatefulViewController](https://github.com/aschuch/StatefulViewController) by [Alexander Schuch](https://twitter.com/schuchalexander) with some minor differences.

## License

StateViewController is available under the MIT license. See the LICENSE file for more info.
