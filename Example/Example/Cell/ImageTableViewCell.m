//
//  ImageTableViewCell.m
//  Example
//
//  Created by Pavol Kmeť on 29/06/2017.
//  Copyright © 2017 Pavol Kmeť. All rights reserved.
//

#import "ImageTableViewCell.h"

@implementation ImageTableViewCell

- (void)prepareForReuse
{
    [super prepareForReuse];
    
    self.thumbnailImageView.image = nil;
}

- (void)configureWithPage:(Page *)page
{
    self.titleLabel.text = page.title;
    if (page.thumbnail.source) {
        [self.thumbnailImageView setImageWithURL:page.thumbnail.source];
    }
}

@end
