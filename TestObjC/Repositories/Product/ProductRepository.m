//
//  ProductRepository.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import "ProductRepository.h"
#import "Tag.h"
#import "ApiResPromotion.h"
#import "Product.h"

@implementation ProductRepository

- (NSArray<Tag*> *)getCatalog { 
    NSMutableArray<Tag*> *tags = [[NSMutableArray alloc] init];
    ApiResPromotion *resPromotion;
    dispatch_semaphore_t sema = dispatch_semaphore_create(0);

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"https://central.udacodingtest.webtes.biz.id/promotion-v2"]
      cachePolicy:NSURLRequestUseProtocolCachePolicy
      timeoutInterval:10.0];
    
    NSDictionary *headers = @{
      @"Authorization": @"Bearer eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiIsImp0aSI6ImNkY2Q1MDJhZjMxNzZmZGNiNzI1NDk3MjE3MGJiZWYzZTY5Nzg4ZTNiNTE0Zjc0YjAzYzM4ZjkwYTM0NTk2YmQ1OGI5MDM0ZTE0ZTRkMjRkIn0.eyJhdWQiOiIxIiwianRpIjoiY2RjZDUwMmFmMzE3NmZkY2I3MjU0OTcyMTcwYmJlZjNlNjk3ODhlM2I1MTRmNzRiMDNjMzhmOTBhMzQ1OTZiZDU4YjkwMzRlMTRlNGQyNGQiLCJpYXQiOjE3MTM4MTcwNTIsIm5iZiI6MTcxMzgxNzA1MiwiZXhwIjoxNzQ1MzUzMDUyLCJzdWIiOiIxIiwic2NvcGVzIjpbImFkbWluOmNlbnRyYWwiXX0.Bi6z5ikzIrwAamlei98ZewuGo02GOQlaRSjXeITGa2D3r9KcBlaWB37C-Rjz9HM4rc7arxNJe7XDbJVOn-q1VSNOudUEyqyoS_NjiC_sqGOTcWsSiK2Eqtt_EiigmNlkT7hI0oQzNCCgescseI9N-ZeUe8u7I4Cr5AaBb7T3uCsTCwBQa8dxm5pcMB-7I1nmWgSvGhNQ2DfzYBNEmiI81MscdYAJ4F3ZTbCi0DwkwOK7QXfcm_bhQFUJzbUH_i4VNFY_crBsvjWpHn25r0FykQp8v7OYKUB45cgtzK_BP2dICjLRPGyKTQBjUuunP4Biy7VrzSLnBNc7B41Iz2xGkdvVsBS-cOPRyX_ghAHCq73pYynLYIedwzN-faAYcPfXTBPEnftQOlarO1ZdUKeQ_Qi0OhAYEhmOGRWHN9Ln0xZQHAksjtHuG4CfZVx4RIBf81yvbUuKBhk1tk2nNcKFvRHWAaJx07mluHpKyBG6mPorwO5tfTMR7Y7utUc3wBykUgdnIA_OruvKvtmVRgriMsLx51X7C28oMoSwiQYbWLh_EdgVLmMsvwFhe6Isr1Ts5S7J3erbJTl3-sroQZ-wZTtLKWXyCQapYN9pcNo9_X8N4EqIOG9__DI2Qjok3pJNBG50vHiAzGTyTjaYnBNUNx8hl8MdMAQArPnWKu8Yu2M"
    };

    [request setAllHTTPHeaderFields:headers];

    [request setHTTPMethod:@"GET"];

    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request
    completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
      if (error) {
        NSLog(@"%@", error);
        dispatch_semaphore_signal(sema);
      } else {
          NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
          NSError *parseError = nil;
          NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&parseError];
          
          NSLog(@"%@",responseDictionary);
          
          NSError *error;
          NSString *rawString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
          
          
          ApiResPromotion *resPromotion = [ApiResPromotion fromJSON:rawString encoding:NSUTF8StringEncoding error:&error];
//                    @property(nonatomic) NSInteger promotionid;
//                    @property(nonatomic) NSString *name;
//                    @property(nonatomic) PromoType *type;
//                    @property(nonatomic) BOOL isAvailable;
//                    @property(nonatomic) NSInteger minSpending;
//                    @property(nonatomic) NSMutableArray<ProductCombo *> *productCombo;
//                    @property(nonatomic) NSMutableArray<ProductBOGO *> *productBogo;
//                    @property(nonatomic) NSMutableArray<Voucher *> *vouchers;
//          // Mapping
                Tag *tagCombo = [[Tag alloc] init];
                    tagCombo.name = @"Combo Promotion";
                    tagCombo.promotions = [[NSMutableArray alloc] init];
                    for (ApiCombo* c in resPromotion.data.combo) {
                        Promotion *promo = [[Promotion alloc] initWithValue:c.identifier name:c.name type:Combo isAvailable:c.isAvailable minSpending:0];
          
                        ProductCombo *productCombo = [[ProductCombo alloc] init];
                        for (ApiFluffyProduct *p in c.meta.products) {
                            Product *product = [[Product alloc] initWithValue:p.identifier categoryId:p.categoryID priceType:p.priceType status:p.status name:p.name code:p.code unitPrice:p.unitPrice qty:1];
                            productCombo.price = [product.unitPrice intValue];
                            [productCombo.products addObject:product];
                            [promo.productCombo addObject:productCombo];
                            [tagCombo.promotions addObject:promo];
                        }
                    }
          
                        Tag *tagBogo = [[Tag alloc] init];
                            tagBogo.name = @"Buy 1 Get 1 Free";
                        tagBogo.promotions = [[NSMutableArray alloc] init];
                        for (ApiBogo* c in resPromotion.data.bogo) {
                            Promotion *promo = [[Promotion alloc] initWithValue:c.identifier name:c.name type:BOGO isAvailable:c.isAvailable minSpending:0];
          
                            ProductBOGO *productBogo = [[ProductBOGO alloc] init];
                            ApiProduct *pf = c.meta.cp.productFree;
                            Product *productFree = [[Product alloc] initWithValue:pf.identifier categoryId:pf.categoryID priceType:pf.priceType status:pf.status name:pf.name code:pf.code unitPrice:pf.unitPrice qty:1];
                            for (ApiPurpleProduct *p in c.meta.cp.comboPurchase.meta.products) {
                                Product *product = [[Product alloc] initWithValue:p.identifier categoryId:p.categoryID priceType:p.priceType status:p.status name:p.name code:p.code unitPrice:p.unitPrice qty:[p.qty intValue]];
                                productBogo.product = product;
                                productBogo.productFree = productFree;
                                [promo.productBogo addObject:productBogo];
                                [tagBogo.promotions addObject:promo];
                            }
                        }
          
                    Tag *tagVoucher = [[Tag alloc] init];
                    tagVoucher.name = @"Voucher";
                    tagVoucher.promotions = [[NSMutableArray alloc] init];
                    for (ApiVoucher* c in resPromotion.data.voucher) {
                        Promotion *promo = [[Promotion alloc] initWithValue:c.identifier name:c.name type:BOGO isAvailable:c.isAvailable minSpending:c.minSpending];
          
                        Voucher *productVoucher = [[Voucher alloc] initWithValue:c.identifier name:c.name type:c.type isAbailable:c.isAvailable minSpending:c.minSpending];
                        [promo.vouchers addObject:productVoucher];
                        [tagVoucher.promotions addObject:promo];
                    }
                        
          [tags addObject:tagCombo];
          [tags addObject:tagBogo];
          [tags addObject:tagVoucher];
        }
          
        dispatch_semaphore_signal(sema);
    }];
    [dataTask resume];
    dispatch_semaphore_wait(sema, DISPATCH_TIME_FOREVER);
    NSLog(@"asasdasdasd");
    
    return tags;
}

@end
