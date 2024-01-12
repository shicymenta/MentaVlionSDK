//
//  MVlionLocation.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionLocation : NSObject

/// 经度
@property (nonatomic, copy) NSString *longitude;

/// 纬度
@property (nonatomic, copy) NSString *latitude;

@end

NS_ASSUME_NONNULL_END
