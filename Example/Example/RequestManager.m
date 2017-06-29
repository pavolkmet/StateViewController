//
//  RequestManager.m
//  Example
//
//  Created by Pavol Kmet on 29/06/2017.
//  Copyright © 2017 GoodRequest. All rights reserved.
//

#import "RequestManager.h"

NSString * const kBaseURL = @"https://en.wikipedia.org/api/rest_v1/";

@implementation RequestManager

#pragma mark - Singleton

+ (RequestManager *)sharedManager
{
    static RequestManager *sharedManager;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        sharedManager = [[RequestManager alloc] initWithBaseURL:[NSURL URLWithString:kBaseURL]];
        sharedManager.requestSerializer = [AFJSONRequestSerializer serializer];
    });
    
    return sharedManager;
}

- (void)relatedPagesShowError:(BOOL)showError
                    showEmpty:(BOOL)showEmpty
                      success:(void(^)(NSArray<Page *> *relatedPages))success
                      failure:(void(^)(NSError *error))failure;
{
    [self GET:@"page/related/Swift" parameters:nil progress:nil success:^(NSURLSessionDataTask *task, id responseObject) {
        
        NSError *error;
        NSArray<Page *> *relatedpages = [Page arrayOfModelsFromDictionaries:responseObject[@"pages"] error:&error];
        
        if (error) {
            if (failure) {
                failure(error);
            }
        } else if (showError) {
            if (failure) {
                failure([NSError errorWithDomain:@"com.goodrequest.TestError" code:-1 userInfo:nil]);
            }
        } else if (showEmpty) {
            if (success) {
                success(nil);
            }
        } else {
            if (success) {
                success(relatedpages);
            }
        }
    } failure:^(NSURLSessionDataTask *task, NSError *error) {
        if (failure) {
            failure(error);
        }
    }];
}

@end
