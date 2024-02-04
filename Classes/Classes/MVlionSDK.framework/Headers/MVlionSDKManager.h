//
//  MVlionSDKManager.h
//  MentaVlionSDK
//
//  Created by iMacMe on 2023/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class MVlionUser, MVlionLocation;
@interface MVlionSDKManager : NSObject

/**
 * @brief 初始化方法
 * @param appId 广告应用标识
 * @param finishBlock 初始化回调
 */
+ (void)registerAppId:(NSString *)appId finishBlock:(void(^)(BOOL success,  NSError * _Nullable error))finishBlock;


/**
 * @brief 版本号
 * @discussion SDK Version 版本号
 */
+ (NSString *)sdkVersion;

/**
 * @brief 初始化状态
 * @discussion 检查  SDK 是否已经初始化成功
 */
+ (BOOL)isInitialized;

/**
 * @brief 日志开关
 * @param enableLog Debug模式 默认为 NO
 * @discussion 是否开启log 日志，可选
 */
+ (void)enableLog:(BOOL)enableLog;

/**
 * @brief 设置ua 外部传入ua后内部不再进行获取ua的操作
 * @discussion iOS ua 为系统全局属性, 一旦更改SDK内部会获取更改后的ua,为避免此情况, 开发者需根据自身情况获取ua 然后原始ua传入MVlionSDK
 */
+ (void)setCustomUA:(NSString *)ua;


/**
 * @brief 地理位置开关
 * @param isCanUseLocation 默认为YES  SDK内部不向iPhone申请地理权限 只是当地理权限可用时获取经纬度
 * @discussion 是否允许 SDK 使用地理位置权限 ，可选
 */
+ (void)canUseLocation:(BOOL)isCanUseLocation;

/**
 * @brief 设置地理位置
 * @param location 传入的地理位置
 * @discussion 当isCanUseLocation = NO时，可传入地理位置信息， SDK 使用您传入的地理位置信息，可选
 */
+ (void)setUserLocation:(MVlionLocation *)location;

/**
 * @brief 设置用户信息
 */
+ (void)setUserInfo:(MVlionUser *)user;

/**
 * @brief IDFA开关
 * @param isCanUseIDFA 是否允许
 * @discussion 是否允许使用IDFA， 不设置则默认为YES；设置为NO时，IDFA权限不可用，可通过setCustomIDFA传入有效的IDFA值
 */
+ (void)canUseIDFA:(BOOL)isCanUseIDFA;



/**
 * @brief 设置idfa值
 * @param idfa 传入idfa值，可选配置
 * @discussion 可通过该方法传入您的IDFA值, isCanUseIDFA = YES 时 该设置无效, 若您的app有自己获取idfa的获取策略 则将 isCanUseIDFA置为NO, 然后设置该值即可生效
 */
+ (void)setCustomIDFA:(NSString *)idfa;


/**
 * @brief 是否使用聚合SDK(MentaUnifiedSDK)管理MentaVlionSDK
 * @param isAggregation 默认 YES
 * @discussion 如果果您没有集成MentaUnifiedSDK 只是单独的集成了MVlionSDK 请务必将该属性置为NO 否则一些属性不生效
 */
+ (void)setUseAggregation:(BOOL)isAggregation;

@end

NS_ASSUME_NONNULL_END
