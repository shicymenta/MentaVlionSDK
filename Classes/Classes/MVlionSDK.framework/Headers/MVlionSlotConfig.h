//
//  MVlionSlotConfig.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MVlionSlotConfig : NSObject

@property (nonatomic) CGSize adSize;// 广告位尺寸 所有广告位必须要传 包括开屏
@property (nonatomic, copy) NSString *slotId;// 广告位id
@property (nonatomic, assign) NSInteger bidFloor;// 底价 默认 0



#pragma mark 开发者不必理会该字段, 勿传
@property (nonatomic, strong) NSDictionary *adTemplate __deprecated_msg("adTemplate 已过期废弃"); // 模版信息

@end

NS_ASSUME_NONNULL_END
