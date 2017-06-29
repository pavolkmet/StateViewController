//
//  Image.h
//  Example
//
//  Created by Pavol Kmet on 29/06/2017.
//  Copyright © 2017 GoodRequest. All rights reserved.
//

#import <JSONModel/JSONModel.h>

@interface Image : JSONModel

@property (strong, nonatomic) NSURL *source;
@property (strong, nonatomic) NSNumber *width;
@property (strong, nonatomic) NSNumber *height;

@end
