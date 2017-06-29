//
//  ImageTableViewCell.h
//  Example
//
//  Created by Pavol Kmet on 29/06/2017.
//  Copyright © 2017 GoodRequest. All rights reserved.
//

#import <AFNetworking/UIImageView+AFNetworking.h>
#import <UIKit/UIKit.h>
#import "Page.h"

@interface ImageTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *thumbnailImageView;
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;

- (void)configureWithPage:(Page *)page;

@end
