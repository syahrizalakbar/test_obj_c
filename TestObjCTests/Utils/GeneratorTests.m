//
//  GeneratorTests.m
//  TestObjCTests
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import <XCTest/XCTest.h>
#import "Generator.h"

@interface GeneratorTests : XCTestCase

@end

@implementation GeneratorTests

-(void) testUuid{
    NSString *uuid = [Generator generateUUID];
    
    XCTAssertNotNil(uuid, @"Generated UUID should not be nil");
    
    // Regular expression to match the UUID format (e.g., 8-4-4-4-12 hexadecimal digits)
    NSString *uuidRegex = @"^[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}$";
    NSPredicate *uuidTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", uuidRegex];
        
    XCTAssertTrue([uuidTest evaluateWithObject:uuid], @"Generated UUID should match the expected format");
}

@end
