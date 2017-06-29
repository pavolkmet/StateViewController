//
//  Page.h
//  Example
//
//  Created by Pavol Kmet on 29/06/2017.
//  Copyright © 2017 GoodRequest. All rights reserved.
//

#import <JSONModel/JSONModel.h>
#import "Image.h"

@interface Page : JSONModel

@property (strong, nonatomic) NSNumber *pageID;
@property (strong, nonatomic) NSString *title;
@property (strong, nonatomic) NSString *extract;
@property (strong, nonatomic) Image *thumbnail;

@end
