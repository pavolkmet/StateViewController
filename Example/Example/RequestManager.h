//
//  RequestManager.h
//  Example
//
//  Created by Pavol Kmeť on 29/06/2017.
//  Copyright © 2017 Pavol Kmeť. All rights reserved.
//

#import <AFNetworking/AFNetworking.h>
#import "Page.h"

@interface RequestManager : AFHTTPSessionManager

+ (RequestManager *)sharedManager;

- (void)relatedPagesShowError:(BOOL)showError
                    showEmpty:(BOOL)showEmpty
                      success:(void(^)(NSArray<Page *> *relatedPages))success
                      failure:(void(^)(NSError *error))failure;

@end
