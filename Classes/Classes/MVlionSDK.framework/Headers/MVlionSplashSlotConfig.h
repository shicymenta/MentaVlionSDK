//
//  MVlionSplashSlotConfig.h
//  MVlionSDK
//
//  Created by iMacMe on 2024/1/4.
//

#import <MVlionSDK/MVlionSDK.h>
#import <MentaVlionBaseSDK/MentaVlionCommonEnum.h>
NS_ASSUME_NONNULL_BEGIN

@interface MVlionSplashSlotConfig : MVlionSlotConfig

// 其他属性见基类


/// 广告交互方式 默认 MentaSplashAdInterviewMode_BottomHotSpotClick
/// 可传入多种 详情见demo
@property(nonatomic, assign) MentaSplashAdInterviewMode interviewMode;

/// 素材填充方式 默认 MentaSplashAdMaterialFillMode_ScaleAspectFill
@property(nonatomic, assign) MentaSplashAdMaterialFillMode materialFillMode;

/// 开屏广告持续秒数 默认5
@property(nonatomic, assign) NSInteger maxSec;

/// 开屏广告摇一摇模式下的灵敏度 默认500
@property(nonatomic, assign) NSInteger shakeRange;

/// 开屏广告摇一摇模式下扭动的灵敏度 默认500
@property(nonatomic, assign) NSInteger twistRange;

/// 开屏广告上滑模式下的触发滑动方法的滑动距离 默认 20
@property(nonatomic, assign) NSInteger swipeRange;


/// 底部logo
@property(nonatomic, strong) UIView *bottomView;

/// 当前控制器
@property(nonatomic, weak) UIViewController *viewController;


@end

NS_ASSUME_NONNULL_END
