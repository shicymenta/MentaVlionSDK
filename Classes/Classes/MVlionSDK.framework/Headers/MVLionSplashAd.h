//
//  MVLionSplashAd.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/14.
//

#import <UIKit/UIKit.h>

@class MVLionSplashAd;
@class MVlionSlotConfig;
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MVLionSplashAdCloseMode) {
    MVLionSplashAdCloseMode_ByClickAd,        // 点击广告关闭
    MVLionSplashAdCloseMode_ByClickSkip,      // 点击跳过
    MVLionSplashAdCloseMode_TimeOver,         // 倒计时结束时关闭
};


typedef NS_ENUM(NSUInteger, MVLionSplashAdInterviewMode) {
    MVLionSplashAdInterviewMode_BottomHotSpotClick,   // 底部热区点击 // 默认
    MVLionSplashAdInterviewMode_FullScreenClick,      // 全屏可点
};

typedef NS_ENUM(NSUInteger, MVLionSplashAdMaterialFillMode) {
    MVLionSplashAdMaterialFillMode_ScaleAspectFill, // 默认
    MVLionSplashAdMaterialFillMode_ScaleToFill,
    MVLionSplashAdMaterialFillMode_ScaleAspectFit,
};


@protocol MVLionSplashAdDelegate <NSObject>

@optional
/// 开屏广告数据拉取成功
- (void)mvlion_splashAdDidLoad:(MVLionSplashAd *)splashAd;

/// 开屏广告物料加载成功
- (void)mvlion_splashAdMaterialDidLoad:(MVLionSplashAd *)splashAd;

/// 开屏加载失败
- (void)mvlion_splashAd:(MVLionSplashAd *)splashAd didFailWithError:(NSError * _Nullable)error;

/// 开屏广告被点击了
- (void)mvlion_splashAdDidClick:(MVLionSplashAd *)splashAd;

/// 开屏广告关闭了
- (void)mvlion_splashAdDidClose:(MVLionSplashAd *)splashAd closeMode:(MVLionSplashAdCloseMode)mode;

/// 开屏广告详情页面关闭的回调
- (void)mvlion_splashAdDetailDidClosed:(MVLionSplashAd *)splashAd;

///  开屏广告曝光
- (void)mvlion_splashAdDidExpose:(MVLionSplashAd *)splashAd;

@end

@interface MVLionSplashAd : NSObject

/// 开屏广告代理
@property(nonatomic,weak)id <MVLionSplashAdDelegate> delegate;

/// 广告id 只读，开发者不允许修改
@property(nonatomic, copy, readonly) NSString *slotId;

/// 当前广告的价格 在 -mvlion_splashAdDidLoad回调之后才能正确获取
@property (nonatomic, assign, readonly) NSInteger price;


/// 广告交互方式 默认 MVLionSplashAdInterviewMode_BottomHotSpotClick
@property(nonatomic, assign) MVLionSplashAdInterviewMode interviewMode;

/// 素材填充方式 默认 MVLionSplashAdMaterialFillMode_ScaleAspectFill
@property(nonatomic, assign) MVLionSplashAdMaterialFillMode materialFillMode;

/// 底部logo
@property(nonatomic, strong) UIView *bottomView;

/// 当前控制器
@property(nonatomic,weak) UIViewController *viewController;


/// 初始化方法
/// - Parameter config: 初始化配置
- (instancetype)initWithConfig:(MVlionSlotConfig *)config;


/// 请求广告
- (void)loadAd;


/// 展现广告
/// - Parameters:
///   - window: 想要展现广告的window
///   - bottomView: 底部logo
///   展示规则: 屏幕高度 减去 bottomView的高度,  剩余部分为素材填充区域,  填充规则为 materialFillMode
- (void)showSplashAdInWindow:(UIWindow *)window;

@end

NS_ASSUME_NONNULL_END
