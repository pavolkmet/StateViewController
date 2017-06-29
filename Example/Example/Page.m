//
//  Page.m
//  Example
//
//  Created by Pavol Kmet on 29/06/2017.
//  Copyright © 2017 GoodRequest. All rights reserved.
//

#import "Page.h"

@implementation Page

+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"pageID": @"pageid" }];
}

@end
