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

@end

NS_ASSUME_NONNULL_END
