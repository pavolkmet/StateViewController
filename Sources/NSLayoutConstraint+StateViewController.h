//
// NSLayoutConstraint+StateViewController.h
// StateViewController
//
// Created by Pavol Kmeť
// Copyright (c) 2021 Pavol Kmeť
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

@interface NSLayoutConstraint (StateViewController)

#pragma mark - Helper Methods - Public

/**
 Create constraints explicitly.  Constraints are of the form "view1.attribute = view2.attribute * multiplier + constant"
 */
+ (instancetype)constraintWithItem:(id)view1 attribute:(NSLayoutAttribute)attribute equalToItem:(id)view2 constant:(CGFloat)constant;

/**
 Sets the priority and active state of the constraint.

 @param priority The priority of the constraint.
 @param active The active state of the constraint.
 */
- (void)setPriority:(UILayoutPriority)priority isActive:(BOOL)active;

@end
