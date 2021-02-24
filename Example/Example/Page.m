//
//  Page.m
//  Example
//
//  Created by Pavol Kmeť on 29/06/2017.
//  Copyright © 2017 Pavol Kmeť. All rights reserved.
//

#import "Page.h"

@implementation Page

+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"pageID": @"pageid" }];
}

@end
