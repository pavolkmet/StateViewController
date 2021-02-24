//
//  Image.h
//  Example
//
//  Created by Pavol Kmeť on 29/06/2017.
//  Copyright © 2017 Pavol Kmeť. All rights reserved.
//

#import <JSONModel/JSONModel.h>

@interface Image : JSONModel

@property (strong, nonatomic) NSURL *source;
@property (strong, nonatomic) NSNumber *width;
@property (strong, nonatomic) NSNumber *height;

@end
