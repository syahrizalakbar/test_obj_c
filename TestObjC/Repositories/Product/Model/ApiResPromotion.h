// ApiResPromotion.h

// To parse this JSON:
//
//   NSError *error;
//   ApiResPromotion *resPromotion = [ApiResPromotion fromJSON:json encoding:NSUTF8Encoding error:&error];

#import <Foundation/Foundation.h>

@class ApiResPromotion;
@class ApiData;
@class ApiBogo;
@class ApiMedia;
@class ApiMediaURL;
@class ApiBOGOMeta;
@class ApiCp;
@class ApiComboPurchase;
@class ApiComboPurchaseMeta;
@class ApiPurpleProduct;
@class ApiProduct;
@class ApiPp;
@class ApiProductFree;
@class ApiCombo;
@class ApiComboMeta;
@class ApiFluffyProduct;
@class ApiVoucher;
@class ApiVoucherMeta;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Object interfaces

@interface ApiResPromotion : NSObject
@property (nonatomic, copy)   NSString *status;
@property (nonatomic, copy)   NSString *messsage;
@property (nonatomic, strong) ApiData *data;

+ (_Nullable instancetype)fromJSON:(NSString *)json encoding:(NSStringEncoding)encoding error:(NSError *_Nullable *)error;
+ (_Nullable instancetype)fromData:(NSData *)data error:(NSError *_Nullable *)error;
- (NSString *_Nullable)toJSON:(NSStringEncoding)encoding error:(NSError *_Nullable *)error;
- (NSData *_Nullable)toData:(NSError *_Nullable *)error;
@end

@interface ApiData : NSObject
@property (nonatomic, copy) NSArray<ApiCombo *> *combo;
@property (nonatomic, copy) NSArray<ApiBogo *> *bogo;
@property (nonatomic, copy) NSArray<ApiVoucher *> *voucher;
@end

@interface ApiBogo : NSObject
@property (nonatomic, assign)         NSInteger identifier;
@property (nonatomic, copy)           NSString *name;
@property (nonatomic, copy)           NSString *type;
@property (nonatomic, assign)         NSInteger isAvailable;
@property (nonatomic, nullable, copy) id minSpending;
@property (nonatomic, nullable, copy) id openDate;
@property (nonatomic, nullable, copy) id closeDate;
@property (nonatomic, nullable, copy) id openTime;
@property (nonatomic, nullable, copy) id closeTime;
@property (nonatomic, nullable, copy) id days;
@property (nonatomic, strong)         ApiBOGOMeta *meta;
@property (nonatomic, copy)           NSString *createdAt;
@property (nonatomic, copy)           NSString *updatedAt;
@property (nonatomic, nullable, copy) id deletedAt;
@property (nonatomic, copy)           NSArray<ApiMediaURL *> *mediaUrls;
@property (nonatomic, copy)           NSArray<ApiMedia *> *media;
@end

@interface ApiMedia : NSObject
@property (nonatomic, assign) NSInteger identifier;
@property (nonatomic, assign) NSInteger modelID;
@property (nonatomic, copy)   NSString *modelType;
@property (nonatomic, copy)   NSString *collectionName;
@property (nonatomic, copy)   NSString *name;
@property (nonatomic, copy)   NSString *fileName;
@property (nonatomic, copy)   NSString *mimeType;
@property (nonatomic, copy)   NSString *disk;
@property (nonatomic, assign) NSInteger size;
@property (nonatomic, copy)   NSArray *manipulations;
@property (nonatomic, copy)   NSArray *customProperties;
@property (nonatomic, assign) NSInteger orderColumn;
@property (nonatomic, copy)   NSString *createdAt;
@property (nonatomic, copy)   NSString *updatedAt;
@end

@interface ApiMediaURL : NSObject
@property (nonatomic, assign) NSInteger identifier;
@property (nonatomic, copy)   NSString *collectionName;
@property (nonatomic, copy)   NSString *original;
@property (nonatomic, assign) NSInteger orderColumn;
@property (nonatomic, copy)   NSString *s512;
@end

@interface ApiBOGOMeta : NSObject
@property (nonatomic, nullable, strong) ApiCp *cp;
@property (nonatomic, copy)             NSString *type;
@property (nonatomic, nullable, strong) ApiPp *pp;
@end

@interface ApiCp : NSObject
@property (nonatomic, strong) ApiComboPurchase *comboPurchase;
@property (nonatomic, strong) ApiProduct *productFree;
@end

@interface ApiComboPurchase : NSObject
@property (nonatomic, assign)         NSInteger identifier;
@property (nonatomic, copy)           NSString *name;
@property (nonatomic, copy)           NSString *type;
@property (nonatomic, assign)         NSInteger isAvailable;
@property (nonatomic, nullable, copy) id minSpending;
@property (nonatomic, nullable, copy) id openDate;
@property (nonatomic, nullable, copy) id closeDate;
@property (nonatomic, nullable, copy) id openTime;
@property (nonatomic, nullable, copy) id closeTime;
@property (nonatomic, nullable, copy) id days;
@property (nonatomic, strong)         ApiComboPurchaseMeta *meta;
@property (nonatomic, copy)           NSString *createdAt;
@property (nonatomic, copy)           NSString *updatedAt;
@property (nonatomic, nullable, copy) id deletedAt;
@property (nonatomic, copy)           NSArray<ApiMediaURL *> *mediaUrls;
@property (nonatomic, copy)           NSArray<ApiMedia *> *media;
@end

@interface ApiComboPurchaseMeta : NSObject
@property (nonatomic, copy) NSArray<ApiPurpleProduct *> *products;
@end

@interface ApiPurpleProduct : NSObject
@property (nonatomic, assign)         NSInteger identifier;
@property (nonatomic, nullable, copy) id outletID;
@property (nonatomic, assign)         NSInteger categoryID;
@property (nonatomic, copy)           NSString *name;
@property (nonatomic, copy)           NSString *code;
@property (nonatomic, nullable, copy) id theDescription;
@property (nonatomic, nullable, copy) id colorCode;
@property (nonatomic, assign)         NSInteger priceType;
@property (nonatomic, assign)         NSInteger status;
@property (nonatomic, copy)           NSString *unitPrice;
@property (nonatomic, copy)           NSString *cost;
@property (nonatomic, assign)         BOOL isChargeable;
@property (nonatomic, assign)         BOOL isFeatured;
@property (nonatomic, assign)         BOOL isOutOfStock;
@property (nonatomic, assign)         NSInteger allowMediaOverride;
@property (nonatomic, nullable, copy) id availability;
@property (nonatomic, nullable, copy) id availableFrom;
@property (nonatomic, nullable, copy) id availableTo;
@property (nonatomic, copy)           NSString *createdAt;
@property (nonatomic, copy)           NSString *updatedAt;
@property (nonatomic, nullable, copy) id deletedAt;
@property (nonatomic, copy)           NSString *qty;
@property (nonatomic, copy)           NSArray *mediaUrls;
@property (nonatomic, copy)           NSArray *variants;
@end

@interface ApiProduct : NSObject
@property (nonatomic, assign)         NSInteger identifier;
@property (nonatomic, nullable, copy) id outletID;
@property (nonatomic, assign)         NSInteger categoryID;
@property (nonatomic, copy)           NSString *name;
@property (nonatomic, copy)           NSString *code;
@property (nonatomic, nullable, copy) id theDescription;
@property (nonatomic, nullable, copy) id colorCode;
@property (nonatomic, assign)         NSInteger priceType;
@property (nonatomic, assign)         NSInteger status;
@property (nonatomic, copy)           NSString *unitPrice;
@property (nonatomic, copy)           NSString *cost;
@property (nonatomic, assign)         BOOL isChargeable;
@property (nonatomic, assign)         BOOL isFeatured;
@property (nonatomic, assign)         BOOL isOutOfStock;
@property (nonatomic, assign)         NSInteger allowMediaOverride;
@property (nonatomic, nullable, copy) id availability;
@property (nonatomic, nullable, copy) id availableFrom;
@property (nonatomic, nullable, copy) id availableTo;
@property (nonatomic, copy)           NSString *createdAt;
@property (nonatomic, copy)           NSString *updatedAt;
@property (nonatomic, nullable, copy) id deletedAt;
@property (nonatomic, copy)           NSArray *mediaUrls;
@property (nonatomic, copy)           NSArray *variants;
@end

@interface ApiPp : NSObject
@property (nonatomic, strong) ApiProductFree *productFree;
@property (nonatomic, strong) ApiProduct *productPurchase;
@end

@interface ApiProductFree : NSObject
@property (nonatomic, assign)         NSInteger identifier;
@property (nonatomic, nullable, copy) id outletID;
@property (nonatomic, assign)         NSInteger categoryID;
@property (nonatomic, copy)           NSString *name;
@property (nonatomic, copy)           NSString *code;
@property (nonatomic, nullable, copy) id theDescription;
@property (nonatomic, nullable, copy) id colorCode;
@property (nonatomic, assign)         NSInteger priceType;
@property (nonatomic, assign)         NSInteger status;
@property (nonatomic, copy)           NSString *unitPrice;
@property (nonatomic, copy)           NSString *cost;
@property (nonatomic, assign)         BOOL isChargeable;
@property (nonatomic, assign)         BOOL isFeatured;
@property (nonatomic, assign)         BOOL isOutOfStock;
@property (nonatomic, assign)         NSInteger allowMediaOverride;
@property (nonatomic, nullable, copy) id availability;
@property (nonatomic, nullable, copy) id availableFrom;
@property (nonatomic, nullable, copy) id availableTo;
@property (nonatomic, copy)           NSString *createdAt;
@property (nonatomic, copy)           NSString *updatedAt;
@property (nonatomic, nullable, copy) id deletedAt;
@property (nonatomic, copy)           NSArray<ApiMediaURL *> *mediaUrls;
@property (nonatomic, copy)           NSArray *variants;
@end

@interface ApiCombo : NSObject
@property (nonatomic, assign)         NSInteger identifier;
@property (nonatomic, copy)           NSString *name;
@property (nonatomic, copy)           NSString *type;
@property (nonatomic, assign)         NSInteger isAvailable;
@property (nonatomic, nullable, copy) id minSpending;
@property (nonatomic, nullable, copy) id openDate;
@property (nonatomic, nullable, copy) id closeDate;
@property (nonatomic, nullable, copy) id openTime;
@property (nonatomic, nullable, copy) id closeTime;
@property (nonatomic, nullable, copy) id days;
@property (nonatomic, strong)         ApiComboMeta *meta;
@property (nonatomic, copy)           NSString *createdAt;
@property (nonatomic, copy)           NSString *updatedAt;
@property (nonatomic, nullable, copy) id deletedAt;
@property (nonatomic, copy)           NSArray<ApiMediaURL *> *mediaUrls;
@property (nonatomic, copy)           NSArray<ApiMedia *> *media;
@end

@interface ApiComboMeta : NSObject
@property (nonatomic, copy) NSString *price;
@property (nonatomic, copy) NSArray<ApiFluffyProduct *> *products;
@end

@interface ApiFluffyProduct : NSObject
@property (nonatomic, assign)         NSInteger identifier;
@property (nonatomic, nullable, copy) id outletID;
@property (nonatomic, assign)         NSInteger categoryID;
@property (nonatomic, copy)           NSString *name;
@property (nonatomic, copy)           NSString *code;
@property (nonatomic, nullable, copy) id theDescription;
@property (nonatomic, nullable, copy) id colorCode;
@property (nonatomic, assign)         NSInteger priceType;
@property (nonatomic, assign)         NSInteger status;
@property (nonatomic, copy)           NSString *unitPrice;
@property (nonatomic, copy)           NSString *cost;
@property (nonatomic, assign)         BOOL isChargeable;
@property (nonatomic, assign)         BOOL isFeatured;
@property (nonatomic, assign)         BOOL isOutOfStock;
@property (nonatomic, assign)         NSInteger allowMediaOverride;
@property (nonatomic, nullable, copy) id availability;
@property (nonatomic, nullable, copy) id availableFrom;
@property (nonatomic, nullable, copy) id availableTo;
@property (nonatomic, copy)           NSString *createdAt;
@property (nonatomic, copy)           NSString *updatedAt;
@property (nonatomic, nullable, copy) id deletedAt;
@property (nonatomic, copy)           NSString *qty;
@property (nonatomic, copy)           NSArray<ApiMediaURL *> *mediaUrls;
@property (nonatomic, copy)           NSArray *variants;
@end

@interface ApiVoucher : NSObject
@property (nonatomic, assign)         NSInteger identifier;
@property (nonatomic, copy)           NSString *name;
@property (nonatomic, copy)           NSString *type;
@property (nonatomic, assign)         NSInteger isAvailable;
@property (nonatomic, assign)         NSInteger minSpending;
@property (nonatomic, nullable, copy) id openDate;
@property (nonatomic, nullable, copy) id closeDate;
@property (nonatomic, nullable, copy) id openTime;
@property (nonatomic, nullable, copy) id closeTime;
@property (nonatomic, nullable, copy) id days;
@property (nonatomic, strong)         ApiVoucherMeta *meta;
@property (nonatomic, copy)           NSString *createdAt;
@property (nonatomic, copy)           NSString *updatedAt;
@property (nonatomic, nullable, copy) id deletedAt;
@property (nonatomic, copy)           NSArray *mediaUrls;
@property (nonatomic, copy)           NSArray *media;
@end

@interface ApiVoucherMeta : NSObject
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *maxAmount;
@property (nonatomic, copy) NSString *percentage;
@end

NS_ASSUME_NONNULL_END

// ApiResPromotion.m

#import "ApiResPromotion.h"

// Shorthand for simple blocks
#define λ(decl, expr) (^(decl) { return (expr); })

// nil → NSNull conversion for JSON dictionaries
static id NSNullify(id _Nullable x) {
    return (x == nil || x == NSNull.null) ? NSNull.null : x;
}

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Private model interfaces

@interface ApiResPromotion (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiData (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiBogo (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiMedia (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiMediaURL (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiBOGOMeta (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiCp (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiComboPurchase (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiComboPurchaseMeta (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiPurpleProduct (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiProduct (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiPp (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiProductFree (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiCombo (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiComboMeta (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiFluffyProduct (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiVoucher (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

@interface ApiVoucherMeta (JSONConversion)
+ (instancetype)fromJSONDictionary:(NSDictionary *)dict;
- (NSDictionary *)JSONDictionary;
@end

static id map(id collection, id (^f)(id value)) {
    id result = nil;
    if ([collection isKindOfClass:NSArray.class]) {
        result = [NSMutableArray arrayWithCapacity:[collection count]];
        for (id x in collection) [result addObject:f(x)];
    } else if ([collection isKindOfClass:NSDictionary.class]) {
        result = [NSMutableDictionary dictionaryWithCapacity:[collection count]];
        for (id key in collection) [result setObject:f([collection objectForKey:key]) forKey:key];
    }
    return result;
}

#pragma mark - JSON serialization

ApiResPromotion *_Nullable ApiResPromotionFromData(NSData *data, NSError **error)
{
    @try {
        id json = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:error];
        return *error ? nil : [ApiResPromotion fromJSONDictionary:json];
    } @catch (NSException *exception) {
        *error = [NSError errorWithDomain:@"JSONSerialization" code:-1 userInfo:@{ @"exception": exception }];
        return nil;
    }
}

ApiResPromotion *_Nullable ApiResPromotionFromJSON(NSString *json, NSStringEncoding encoding, NSError **error)
{
    return ApiResPromotionFromData([json dataUsingEncoding:encoding], error);
}

NSData *_Nullable ApiResPromotionToData(ApiResPromotion *resPromotion, NSError **error)
{
    @try {
        id json = [resPromotion JSONDictionary];
        NSData *data = [NSJSONSerialization dataWithJSONObject:json options:kNilOptions error:error];
        return *error ? nil : data;
    } @catch (NSException *exception) {
        *error = [NSError errorWithDomain:@"JSONSerialization" code:-1 userInfo:@{ @"exception": exception }];
        return nil;
    }
}

NSString *_Nullable ApiResPromotionToJSON(ApiResPromotion *resPromotion, NSStringEncoding encoding, NSError **error)
{
    NSData *data = ApiResPromotionToData(resPromotion, error);
    return data ? [[NSString alloc] initWithData:data encoding:encoding] : nil;
}

@implementation ApiResPromotion
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"status": @"status",
        @"messsage": @"messsage",
        @"data": @"data",
    };
}

+ (_Nullable instancetype)fromData:(NSData *)data error:(NSError *_Nullable *)error
{
    return ApiResPromotionFromData(data, error);
}

+ (_Nullable instancetype)fromJSON:(NSString *)json encoding:(NSStringEncoding)encoding error:(NSError *_Nullable *)error
{
    return ApiResPromotionFromJSON(json, encoding, error);
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiResPromotion alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _data = [ApiData fromJSONDictionary:(id)_data];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiResPromotion.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiResPromotion.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiResPromotion.properties.allValues] mutableCopy];

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"data": [_data JSONDictionary],
    }];

    return dict;
}

- (NSData *_Nullable)toData:(NSError *_Nullable *)error
{
    return ApiResPromotionToData(self, error);
}

- (NSString *_Nullable)toJSON:(NSStringEncoding)encoding error:(NSError *_Nullable *)error
{
    return ApiResPromotionToJSON(self, encoding, error);
}
@end

@implementation ApiData
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"Combo": @"combo",
        @"BOGO": @"bogo",
        @"Voucher": @"voucher",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiData alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _combo = map(_combo, λ(id x, [ApiCombo fromJSONDictionary:x]));
        _bogo = map(_bogo, λ(id x, [ApiBogo fromJSONDictionary:x]));
        _voucher = map(_voucher, λ(id x, [ApiVoucher fromJSONDictionary:x]));
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiData.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiData.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiData.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiData.properties) {
        id propertyName = ApiData.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"Combo": map(_combo, λ(id x, [x JSONDictionary])),
        @"BOGO": map(_bogo, λ(id x, [x JSONDictionary])),
        @"Voucher": map(_voucher, λ(id x, [x JSONDictionary])),
    }];

    return dict;
}
@end

@implementation ApiBogo
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"name": @"name",
        @"type": @"type",
        @"is_available": @"isAvailable",
        @"min_spending": @"minSpending",
        @"open_date": @"openDate",
        @"close_date": @"closeDate",
        @"open_time": @"openTime",
        @"close_time": @"closeTime",
        @"days": @"days",
        @"meta": @"meta",
        @"created_at": @"createdAt",
        @"updated_at": @"updatedAt",
        @"deleted_at": @"deletedAt",
        @"media_urls": @"mediaUrls",
        @"media": @"media",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiBogo alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _meta = [ApiBOGOMeta fromJSONDictionary:(id)_meta];
        _mediaUrls = map(_mediaUrls, λ(id x, [ApiMediaURL fromJSONDictionary:x]));
        _media = map(_media, λ(id x, [ApiMedia fromJSONDictionary:x]));
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiBogo.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiBogo.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiBogo.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiBogo.properties) {
        id propertyName = ApiBogo.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"meta": [_meta JSONDictionary],
        @"media_urls": map(_mediaUrls, λ(id x, [x JSONDictionary])),
        @"media": map(_media, λ(id x, [x JSONDictionary])),
    }];

    return dict;
}
@end

@implementation ApiMedia
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"model_id": @"modelID",
        @"model_type": @"modelType",
        @"collection_name": @"collectionName",
        @"name": @"name",
        @"file_name": @"fileName",
        @"mime_type": @"mimeType",
        @"disk": @"disk",
        @"size": @"size",
        @"manipulations": @"manipulations",
        @"custom_properties": @"customProperties",
        @"order_column": @"orderColumn",
        @"created_at": @"createdAt",
        @"updated_at": @"updatedAt",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiMedia alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiMedia.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiMedia.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiMedia.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiMedia.properties) {
        id propertyName = ApiMedia.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    return dict;
}
@end

@implementation ApiMediaURL
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"collection_name": @"collectionName",
        @"original": @"original",
        @"order_column": @"orderColumn",
        @"s512": @"s512",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiMediaURL alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiMediaURL.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiMediaURL.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiMediaURL.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiMediaURL.properties) {
        id propertyName = ApiMediaURL.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    return dict;
}
@end

@implementation ApiBOGOMeta
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"cp": @"cp",
        @"type": @"type",
        @"pp": @"pp",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiBOGOMeta alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _cp = [ApiCp fromJSONDictionary:(id)_cp];
        _pp = [ApiPp fromJSONDictionary:(id)_pp];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiBOGOMeta.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiBOGOMeta.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiBOGOMeta.properties.allValues] mutableCopy];

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"cp": NSNullify([_cp JSONDictionary]),
        @"pp": NSNullify([_pp JSONDictionary]),
    }];

    return dict;
}
@end

@implementation ApiCp
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"combo_purchase": @"comboPurchase",
        @"product_free": @"productFree",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiCp alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _comboPurchase = [ApiComboPurchase fromJSONDictionary:(id)_comboPurchase];
        _productFree = [ApiProduct fromJSONDictionary:(id)_productFree];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiCp.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiCp.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiCp.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiCp.properties) {
        id propertyName = ApiCp.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"combo_purchase": [_comboPurchase JSONDictionary],
        @"product_free": [_productFree JSONDictionary],
    }];

    return dict;
}
@end

@implementation ApiComboPurchase
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"name": @"name",
        @"type": @"type",
        @"is_available": @"isAvailable",
        @"min_spending": @"minSpending",
        @"open_date": @"openDate",
        @"close_date": @"closeDate",
        @"open_time": @"openTime",
        @"close_time": @"closeTime",
        @"days": @"days",
        @"meta": @"meta",
        @"created_at": @"createdAt",
        @"updated_at": @"updatedAt",
        @"deleted_at": @"deletedAt",
        @"media_urls": @"mediaUrls",
        @"media": @"media",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiComboPurchase alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _meta = [ApiComboPurchaseMeta fromJSONDictionary:(id)_meta];
        _mediaUrls = map(_mediaUrls, λ(id x, [ApiMediaURL fromJSONDictionary:x]));
        _media = map(_media, λ(id x, [ApiMedia fromJSONDictionary:x]));
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiComboPurchase.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiComboPurchase.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiComboPurchase.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiComboPurchase.properties) {
        id propertyName = ApiComboPurchase.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"meta": [_meta JSONDictionary],
        @"media_urls": map(_mediaUrls, λ(id x, [x JSONDictionary])),
        @"media": map(_media, λ(id x, [x JSONDictionary])),
    }];

    return dict;
}
@end

@implementation ApiComboPurchaseMeta
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"products": @"products",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiComboPurchaseMeta alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _products = map(_products, λ(id x, [ApiPurpleProduct fromJSONDictionary:x]));
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiComboPurchaseMeta.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiComboPurchaseMeta.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiComboPurchaseMeta.properties.allValues] mutableCopy];

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"products": map(_products, λ(id x, [x JSONDictionary])),
    }];

    return dict;
}
@end

@implementation ApiPurpleProduct
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"outlet_id": @"outletID",
        @"category_id": @"categoryID",
        @"name": @"name",
        @"code": @"code",
        @"description": @"theDescription",
        @"color_code": @"colorCode",
        @"price_type": @"priceType",
        @"status": @"status",
        @"unit_price": @"unitPrice",
        @"cost": @"cost",
        @"chargeable": @"isChargeable",
        @"featured": @"isFeatured",
        @"out_of_stock": @"isOutOfStock",
        @"allow_media_override": @"allowMediaOverride",
        @"availability": @"availability",
        @"available_from": @"availableFrom",
        @"available_to": @"availableTo",
        @"created_at": @"createdAt",
        @"updated_at": @"updatedAt",
        @"deleted_at": @"deletedAt",
        @"qty": @"qty",
        @"media_urls": @"mediaUrls",
        @"variants": @"variants",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiPurpleProduct alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiPurpleProduct.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiPurpleProduct.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiPurpleProduct.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiPurpleProduct.properties) {
        id propertyName = ApiPurpleProduct.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"chargeable": _isChargeable ? @YES : @NO,
        @"featured": _isFeatured ? @YES : @NO,
        @"out_of_stock": _isOutOfStock ? @YES : @NO,
    }];

    return dict;
}
@end

@implementation ApiProduct
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"outlet_id": @"outletID",
        @"category_id": @"categoryID",
        @"name": @"name",
        @"code": @"code",
        @"description": @"theDescription",
        @"color_code": @"colorCode",
        @"price_type": @"priceType",
        @"status": @"status",
        @"unit_price": @"unitPrice",
        @"cost": @"cost",
        @"chargeable": @"isChargeable",
        @"featured": @"isFeatured",
        @"out_of_stock": @"isOutOfStock",
        @"allow_media_override": @"allowMediaOverride",
        @"availability": @"availability",
        @"available_from": @"availableFrom",
        @"available_to": @"availableTo",
        @"created_at": @"createdAt",
        @"updated_at": @"updatedAt",
        @"deleted_at": @"deletedAt",
        @"media_urls": @"mediaUrls",
        @"variants": @"variants",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiProduct alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiProduct.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiProduct.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiProduct.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiProduct.properties) {
        id propertyName = ApiProduct.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"chargeable": _isChargeable ? @YES : @NO,
        @"featured": _isFeatured ? @YES : @NO,
        @"out_of_stock": _isOutOfStock ? @YES : @NO,
    }];

    return dict;
}
@end

@implementation ApiPp
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"product_free": @"productFree",
        @"product_purchase": @"productPurchase",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiPp alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _productFree = [ApiProductFree fromJSONDictionary:(id)_productFree];
        _productPurchase = [ApiProduct fromJSONDictionary:(id)_productPurchase];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiPp.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiPp.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiPp.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiPp.properties) {
        id propertyName = ApiPp.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"product_free": [_productFree JSONDictionary],
        @"product_purchase": [_productPurchase JSONDictionary],
    }];

    return dict;
}
@end

@implementation ApiProductFree
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"outlet_id": @"outletID",
        @"category_id": @"categoryID",
        @"name": @"name",
        @"code": @"code",
        @"description": @"theDescription",
        @"color_code": @"colorCode",
        @"price_type": @"priceType",
        @"status": @"status",
        @"unit_price": @"unitPrice",
        @"cost": @"cost",
        @"chargeable": @"isChargeable",
        @"featured": @"isFeatured",
        @"out_of_stock": @"isOutOfStock",
        @"allow_media_override": @"allowMediaOverride",
        @"availability": @"availability",
        @"available_from": @"availableFrom",
        @"available_to": @"availableTo",
        @"created_at": @"createdAt",
        @"updated_at": @"updatedAt",
        @"deleted_at": @"deletedAt",
        @"media_urls": @"mediaUrls",
        @"variants": @"variants",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiProductFree alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _mediaUrls = map(_mediaUrls, λ(id x, [ApiMediaURL fromJSONDictionary:x]));
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiProductFree.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiProductFree.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiProductFree.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiProductFree.properties) {
        id propertyName = ApiProductFree.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"chargeable": _isChargeable ? @YES : @NO,
        @"featured": _isFeatured ? @YES : @NO,
        @"out_of_stock": _isOutOfStock ? @YES : @NO,
        @"media_urls": map(_mediaUrls, λ(id x, [x JSONDictionary])),
    }];

    return dict;
}
@end

@implementation ApiCombo
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"name": @"name",
        @"type": @"type",
        @"is_available": @"isAvailable",
        @"min_spending": @"minSpending",
        @"open_date": @"openDate",
        @"close_date": @"closeDate",
        @"open_time": @"openTime",
        @"close_time": @"closeTime",
        @"days": @"days",
        @"meta": @"meta",
        @"created_at": @"createdAt",
        @"updated_at": @"updatedAt",
        @"deleted_at": @"deletedAt",
        @"media_urls": @"mediaUrls",
        @"media": @"media",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiCombo alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _meta = [ApiComboMeta fromJSONDictionary:(id)_meta];
        _mediaUrls = map(_mediaUrls, λ(id x, [ApiMediaURL fromJSONDictionary:x]));
        _media = map(_media, λ(id x, [ApiMedia fromJSONDictionary:x]));
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiCombo.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiCombo.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiCombo.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiCombo.properties) {
        id propertyName = ApiCombo.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"meta": [_meta JSONDictionary],
        @"media_urls": map(_mediaUrls, λ(id x, [x JSONDictionary])),
        @"media": map(_media, λ(id x, [x JSONDictionary])),
    }];

    return dict;
}
@end

@implementation ApiComboMeta
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"price": @"price",
        @"products": @"products",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiComboMeta alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _products = map(_products, λ(id x, [ApiFluffyProduct fromJSONDictionary:x]));
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiComboMeta.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiComboMeta.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiComboMeta.properties.allValues] mutableCopy];

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"products": map(_products, λ(id x, [x JSONDictionary])),
    }];

    return dict;
}
@end

@implementation ApiFluffyProduct
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"outlet_id": @"outletID",
        @"category_id": @"categoryID",
        @"name": @"name",
        @"code": @"code",
        @"description": @"theDescription",
        @"color_code": @"colorCode",
        @"price_type": @"priceType",
        @"status": @"status",
        @"unit_price": @"unitPrice",
        @"cost": @"cost",
        @"chargeable": @"isChargeable",
        @"featured": @"isFeatured",
        @"out_of_stock": @"isOutOfStock",
        @"allow_media_override": @"allowMediaOverride",
        @"availability": @"availability",
        @"available_from": @"availableFrom",
        @"available_to": @"availableTo",
        @"created_at": @"createdAt",
        @"updated_at": @"updatedAt",
        @"deleted_at": @"deletedAt",
        @"qty": @"qty",
        @"media_urls": @"mediaUrls",
        @"variants": @"variants",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiFluffyProduct alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _mediaUrls = map(_mediaUrls, λ(id x, [ApiMediaURL fromJSONDictionary:x]));
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiFluffyProduct.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiFluffyProduct.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiFluffyProduct.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiFluffyProduct.properties) {
        id propertyName = ApiFluffyProduct.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"chargeable": _isChargeable ? @YES : @NO,
        @"featured": _isFeatured ? @YES : @NO,
        @"out_of_stock": _isOutOfStock ? @YES : @NO,
        @"media_urls": map(_mediaUrls, λ(id x, [x JSONDictionary])),
    }];

    return dict;
}
@end

@implementation ApiVoucher
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"id": @"identifier",
        @"name": @"name",
        @"type": @"type",
        @"is_available": @"isAvailable",
        @"min_spending": @"minSpending",
        @"open_date": @"openDate",
        @"close_date": @"closeDate",
        @"open_time": @"openTime",
        @"close_time": @"closeTime",
        @"days": @"days",
        @"meta": @"meta",
        @"created_at": @"createdAt",
        @"updated_at": @"updatedAt",
        @"deleted_at": @"deletedAt",
        @"media_urls": @"mediaUrls",
        @"media": @"media",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiVoucher alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
        _meta = [ApiVoucherMeta fromJSONDictionary:(id)_meta];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiVoucher.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiVoucher.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiVoucher.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiVoucher.properties) {
        id propertyName = ApiVoucher.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    // Map values that need translation
    [dict addEntriesFromDictionary:@{
        @"meta": [_meta JSONDictionary],
    }];

    return dict;
}
@end

@implementation ApiVoucherMeta
+ (NSDictionary<NSString *, NSString *> *)properties
{
    static NSDictionary<NSString *, NSString *> *properties;
    return properties = properties ? properties : @{
        @"type": @"type",
        @"max_amount": @"maxAmount",
        @"percentage": @"percentage",
    };
}

+ (instancetype)fromJSONDictionary:(NSDictionary *)dict
{
    return dict ? [[ApiVoucherMeta alloc] initWithJSONDictionary:dict] : nil;
}

- (instancetype)initWithJSONDictionary:(NSDictionary *)dict
{
    if (self = [super init]) {
        [self setValuesForKeysWithDictionary:dict];
    }
    return self;
}

- (void)setValue:(nullable id)value forKey:(NSString *)key
{
    id resolved = ApiVoucherMeta.properties[key];
    if (resolved) [super setValue:value forKey:resolved];
}

- (void)setNilValueForKey:(NSString *)key
{
    id resolved = ApiVoucherMeta.properties[key];
    if (resolved) [super setValue:@(0) forKey:resolved];
}

- (NSDictionary *)JSONDictionary
{
    id dict = [[self dictionaryWithValuesForKeys:ApiVoucherMeta.properties.allValues] mutableCopy];

    // Rewrite property names that differ in JSON
    for (id jsonName in ApiVoucherMeta.properties) {
        id propertyName = ApiVoucherMeta.properties[jsonName];
        if (![jsonName isEqualToString:propertyName]) {
            dict[jsonName] = dict[propertyName];
            [dict removeObjectForKey:propertyName];
        }
    }

    return dict;
}
@end

NS_ASSUME_NONNULL_END
