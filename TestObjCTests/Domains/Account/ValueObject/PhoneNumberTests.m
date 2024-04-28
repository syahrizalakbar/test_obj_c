//
//  PhoneNumberTests.m
//  TestObjCTests
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import <XCTest/XCTest.h>
#import "PhoneNumber.h"

@interface PhoneNumberTests : XCTestCase

@end

@implementation PhoneNumberTests

- (void)testPhoneNumberTooShort {
    PhoneNumber *phoneNumber = [PhoneNumber alloc];
    
    XCTAssertThrows([phoneNumber initWithValue:@"123456"], @"Phone number is too short");
}

- (void)testPhoneNumberTooLong {
    PhoneNumber *phoneNumber = [PhoneNumber alloc];
    
    XCTAssertThrows([phoneNumber initWithValue:@"1234512345123456"], @"Phone number is too long");
}

- (void)testPhoneNumberContainInvalidCharacters {
    PhoneNumber *phoneNumber = [PhoneNumber alloc];
    
    XCTAssertThrows([phoneNumber initWithValue:@"1234512d4512345"], @"Phone number contains invalid characters");
}

- (void)testPhoneNumberContainInvalidCharacters2 {
    PhoneNumber *phoneNumber = [PhoneNumber alloc];
    
    XCTAssertNoThrow([phoneNumber initWithValue:@"++09383242343"], @"Phone number is invalid");
}

- (void)testPhoneNumberIsValid {
    PhoneNumber *phoneNumber = [PhoneNumber alloc];
    
    XCTAssertNoThrow([phoneNumber initWithValue:@"09383242343"], @"Phone number is valid");
}

- (void)testPhoneNumberIsValid2 {
    PhoneNumber *phoneNumber = [PhoneNumber alloc];
    
    XCTAssertNoThrow([phoneNumber initWithValue:@"+09383242343"], @"Phone number is valid2");
}


@end
