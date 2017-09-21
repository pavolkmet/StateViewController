//
// UIViewController+StateViewController.h
// StateViewController
//
// Created by Pavol Kmet
// Copyright (c) 2017 GoodRequest (https://goodrequest.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>


/**
 Protocol which might be adopted by view controller in order to be able to respond to appropriate methods.
 */
@protocol StateViewController <NSObject>

- (BOOL)hasContent;
- (UIEdgeInsets)insetForStateView:(UIView *)stateView;
- (UIView *)configureErrorView:(UIView *)view withError:(NSError *)error;
- (UIView *)configureEmptyView:(UIView *)view;
- (void)handleErrorWhenContentsAvailable:(NSError *)error;

@end

/** 
 Enum which represents all possible states of a state view controller.
 */
typedef enum : NSUInteger {
    StateViewControllerStateContent,
    StateViewControllerStateLoading,
    StateViewControllerStateError,
    StateViewControllerStateEmpty,
} StateViewControllerState;

@interface UIViewController (StateViewController) <StateViewController>

/**
 The container view. It's usually a UIViewController's view. All views will be added to this view instance.
 */
@property (strong, nonatomic) UIView *containerView;

/**
 The loading view is shown when the `startLoading` method gets called and `hasContent` method returns false.
 */
@property (strong, nonatomic) UIView *loadingView;

/**
 The error view is shown when loading ends and when the `endLoading` method has an error.
 */
@property (strong, nonatomic) UIView *errorView;

/**
 The empty view is shown when loading ends and when the `hasContent` method returns false.
 */
@property (strong, nonatomic) UIView *emptyView;

/**
 The current state of view controller.
 */
@property (assign, nonatomic) StateViewControllerState currentState;

#pragma mark - Initial state

/**
 Sets up the initial state of the view. This method should be called as soon as possible in view controller's life cycle, 
 e.g. `viewWillAppear:` to transition to the appropriate state.
 */
- (void)setupInitialState;

/**
 Sets up the initial state of the view. This method should be called as soon as possible in view controller's life cycle, 
 e.g. `viewWillAppear:`, to transition to the appropriate state.

 @param completion A block object to be executed when the animation sequence ends.
 */
- (void)setupInitialStateCompletion:(void (^)(void))completion;

#pragma mark - Transitions

/**
 Transitions the view controller to the loading state and shows the loading view if there is no content shown already.

 @param animated If YES, the loading view is being added to hierarchy using an animation.
 @param completion A block object to be executed when the animation sequence ends.
 */
- (void)startLoadingAnimated:(BOOL)animated completion:(void (^)(void))completion;

/**
 Ends the view controller's loading state. If an error occured, the error view is shown. If the `hasContent` method returns false
 after calling this method, the empty view is shown.

 @param animated If YES, the view is being added or removed from view hierarchy using an animation based on view controller state.
 @param completion A block object to be executed when the animation sequence ends.
 */
- (void)endLoadingAnimated:(BOOL)animated completion:(void (^)(void))completion;

/**
 Ends the view controller's loading state. If an error occured, the error view is shown. If the `hasContent` method returns false 
 after calling this method, the empty view is shown.

 @param animated If YES, the view is being added or removed from view hierarchy using an animation based on view controller state.
 @param error An error that might have occured while loading.
 @param completion A block object to be executed when the animation sequence ends.
 */
- (void)endLoadingAnimated:(BOOL)animated error:(NSError *)error completion:(void (^)(void))completion;

@end
