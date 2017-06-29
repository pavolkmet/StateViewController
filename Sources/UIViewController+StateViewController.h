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

@protocol StateViewController <NSObject>

- (BOOL)hasContent;
- (UIEdgeInsets)insetForStateView:(UIView *)stateView;
- (void)handleErrorWhenContentsAvailable:(NSError *)error;


@end

typedef enum : NSUInteger {
    StateViewControllerStateContent,
    StateViewControllerStateLoading,
    StateViewControllerStateError,
    StateViewControllerStateEmpty,
} StateViewControllerState;

@interface UIViewController (StateViewController) <StateViewController>

@property (strong, nonatomic) UIView *containerView;
@property (strong, nonatomic) UIView *loadingView;
@property (strong, nonatomic) UIView *errorView;
@property (strong, nonatomic) UIView *emptyView;

@property (assign, nonatomic) StateViewControllerState currentState;

- (void)setupInitialState;
- (void)setupInitialStateCompletion:(void (^)(void))completion;

- (void)startLoadingAnimated:(BOOL)animated completion:(void (^)(void))completion;
- (void)endLoadingAnimated:(BOOL)animated completion:(void (^)(void))completion;
- (void)endLoadingAnimated:(BOOL)animated error:(NSError *)error completion:(void (^)(void))completion;

@end
