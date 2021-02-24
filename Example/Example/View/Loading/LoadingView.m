//
//  LoadingView.m
//  Example
//
//  Created by Pavol Kmeť on 28/06/2017.
//  Copyright © 2017 Pavol Kmeť. All rights reserved.
//

#import "LoadingView.h"

@interface LoadingView ()

@property (weak, nonatomic) UIView *view;

@end

@implementation LoadingView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self loadNibFromClass:[self class]];
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
