//
//  ImageTableViewCell.h
//  Example
//
//  Created by Pavol Kmeť on 29/06/2017.
//  Copyright © 2017 Pavol Kmeť. All rights reserved.
//

#import <AFNetworking/UIImageView+AFNetworking.h>
#import <UIKit/UIKit.h>
#import "Page.h"

@interface ImageTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *thumbnailImageView;
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;

- (void)configureWithPage:(Page *)page;

@end
