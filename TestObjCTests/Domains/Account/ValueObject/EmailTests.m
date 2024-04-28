//
//  EmailTests.m
//  TestObjCTests
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import <XCTest/XCTest.h>
#import "Email.h"

@interface EmailTests : XCTestCase

@end

@implementation EmailTests


- (void)testEmailShouldBeInvalid1 {
    Email *email = [Email alloc];
    
    XCTAssertThrows([email initWithValue:@"asds"], @"Email is Invalid");
}

- (void)testEmailShouldBeInvalid2 {
    Email *email = [Email alloc];
    
    XCTAssertThrows([email initWithValue:@"asds@"], @"Email is Invalid 2");
}

- (void)testEmailShouldBeInvalid3 {
    Email *email = [Email alloc];
    
    XCTAssertThrows([email initWithValue:@"asds@asdss"], @"Email is Invalid 3");
}

- (void)testEmailShouldBeInvalid4 {
    Email *email = [Email alloc];
    
    XCTAssertThrows([email initWithValue:@"asds@asdss."], @"Email is Invalid 4");
}

- (void)testEmailShouldBeInvalid5 {
    Email *email = [Email alloc];
    
    XCTAssertThrows([email initWithValue:@"s@s.s"], @"Email is Invalid 5");
}

- (void)testEmailShouldBeValid {
    Email *email = [Email alloc];
    
    XCTAssertNoThrow([email initWithValue:@"sasd@sss.sss"], @"Email is Invalid");
}


@end
