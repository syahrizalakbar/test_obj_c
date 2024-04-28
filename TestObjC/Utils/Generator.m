//
//  Generator.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import "Generator.h"

@implementation Generator

+(NSString *) generateUUID {
    return [[NSUUID UUID] UUIDString];
}

@end
