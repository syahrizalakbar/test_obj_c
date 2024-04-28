//
//  UserManagementViewController.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "UserManagementViewController.h"
#import "AccountManagement.h"
#import "ItemAccountCollectionViewCell.h"

@interface UserManagementViewController ()<UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>

@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;
@property (atomic) Account *selectedAccount;
@property (nonatomic, strong) UIDatePicker *datePicker;
@property (nonatomic, strong) NSIndexPath *selectedIndexPath;
@property (weak, nonatomic) IBOutlet UIButton *editProfile;

@end

@implementation UserManagementViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _accountManagement = [[AccountManagement alloc] init];
    [_accountManagement getAllAcounts];
//    [_name setText:@"Rizal"];
//    [_email setText:@"sffs@gmail.com"];
//    [_birthdate setText:@"10-10-1999"];
//    [_phoneNumber setText:@"+2834824243"];
//    [_address setText:@"asads"];
    
    /// Register Nib
    UINib *nib = [UINib nibWithNibName:@"ItemAccountCollectionViewCell" bundle:nil];
    [_accountCollectionView registerNib:nib forCellWithReuseIdentifier:@"itemAccount"];
    
    /// Setup border
    [_sideView.layer setBorderWidth:1];
    [_sideView.layer setCornerRadius:20];
    [_sideView.layer setBorderColor:[UIColor grayColor].CGColor];
    /// Setup icon search
    UIView *containerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 30, 20)];
    UIImageView *iconImageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"ic_search"]];
    iconImageView.contentMode = UIViewContentModeScaleAspectFit;
    iconImageView.frame = CGRectMake(0, 0, 20, 20);
    [containerView addSubview:iconImageView];
    _search.rightView = containerView;
    _search.rightViewMode = UITextFieldViewModeAlways;
    /// Setup icon datepicker
    UIView *containerView2 = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 30, 20)];
    UIButton *chevronButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage *chevronImage = [UIImage imageNamed:@"ic_arrow_down"];
    [chevronButton setImage:chevronImage forState:UIControlStateNormal];
    chevronButton.frame = CGRectMake(0, 0, chevronImage.size.width, chevronImage.size.height);
    [chevronButton addTarget:self action:@selector(pickBirthdate) forControlEvents:UIControlEventTouchUpInside];
    [containerView2 addSubview:chevronButton];
    _birthdate.rightView = containerView2;
    _birthdate.rightViewMode = UITextFieldViewModeAlways; // Show the rightView always
}

- (void)pickBirthdate {
    // Create a UIAlertController
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"     " message:nil preferredStyle:UIAlertControllerStyleAlert];

        // Create a UIDatePicker
        UIDatePicker *datePicker = [[UIDatePicker alloc] init];
        datePicker.datePickerMode = UIDatePickerModeDate;

        // Add a target for value change event
        [datePicker addTarget:self action:@selector(datePickerValueChanged:) forControlEvents:UIControlEventValueChanged];

        // Add the date picker as a subview to the alert controller
        [alertController.view addSubview:datePicker];

        // Add actions for Done and Cancel buttons
        [alertController addAction:[UIAlertAction actionWithTitle:@"Done" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            // Handle Done button tap (optional)
            // For example, you can perform additional actions or dismiss the alert controller
            [self handleDatePickerDone];
        }]];
        [alertController addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:nil]];

        // Present the alert controller
        [self presentViewController:alertController animated:YES completion:nil];
}

// Method to handle date picker value change
- (void)datePickerValueChanged:(UIDatePicker *)sender {
    // Handle value change as needed
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    dateFormatter.dateFormat = @"dd-MM-yyyy"; // Customize the date format as needed
    self.birthdate.text = [dateFormatter stringFromDate:sender.date];
}

// Method to handle Done button tap (optional)
- (void)handleDatePickerDone {
    [self.birthdate resignFirstResponder];
}

- (void) addNewAccount {
    [_name setText:@""];
    [_email setText:@""];
    [_birthdate setText:@""];
    [_phoneNumber setText:@""];
    [_address setText:@""];
    [_editProfile setTitle:@"Save Account" forState:UIControlStateNormal];
}

- (IBAction)createAnAccount:(id)sender {
    [_name setText:@""];
    [_email setText:@""];
    [_birthdate setText:@""];
    [_phoneNumber setText:@""];
    [_address setText:@""];
    _selectedAccount = nil;
    [_editProfile setTitle:@"Save Account" forState:UIControlStateNormal];
}

- (Account*) buildAccount {
    Account *acc = [Account alloc];
    NSString *aId = _selectedAccount == nil ? [[AccountID alloc] init].value : _selectedAccount.accountId.value;
    acc = [acc initWithValue:aId withName:_name.text withEmail:_email.text withPhone:_phoneNumber.text withBirthDate:_birthdate.text withAddress:_address.text];
    
    return acc;
}

- (IBAction)onEditSave:(id)sender {
    @try {
        if (_selectedAccount != nil) {
            [_accountManagement editAccount:[self buildAccount]];
        } else {
            [_accountManagement createNewAccount:[self buildAccount]];
            [self createAnAccount:sender];
        }
        
        UICollectionViewCell *previousCell = [_collectionView cellForItemAtIndexPath:self.selectedIndexPath];
        [_accountCollectionView reloadData];
        
        UIAlertController * alert = [UIAlertController
                                        alertControllerWithTitle:@"Success"
                                     message:@"Success"
                                        preferredStyle:UIAlertControllerStyleAlert];
           UIAlertAction* yesButton = [UIAlertAction
                                       actionWithTitle:@"OK"
                                       style:UIAlertActionStyleDefault
                                       handler:^(UIAlertAction * action) {
                                       }];
           [alert addAction:yesButton];
           [self presentViewController:alert animated:YES completion:nil];
        previousCell.backgroundColor = [UIColor clearColor];
    } @catch (NSException *exception) {
        NSLog(@"%@", exception.reason);
        UIAlertController * alert = [UIAlertController
                                        alertControllerWithTitle:@"Form"
                                        message:exception.reason
                                        preferredStyle:UIAlertControllerStyleAlert];
           UIAlertAction* yesButton = [UIAlertAction
                                       actionWithTitle:@"Understand"
                                       style:UIAlertActionStyleDefault
                                       handler:^(UIAlertAction * action) {
                                       }];

           [alert addAction:yesButton];
           [self presentViewController:alert animated:YES completion:nil];
    }
}

- (IBAction)exit:(id)sender {
    [self dismissViewControllerAnimated:true completion:nil];
}



- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return _accountManagement.accounts.count;
}

- (__kindof UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    ItemAccountCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"itemAccount" forIndexPath:indexPath];
    [cell setView:_accountManagement.accounts[indexPath.row].name.value
            phone:_accountManagement.accounts[indexPath.row].phoneNumber.value];
    return cell;
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return 1;
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
//    CGFloat width = collectionView.frame.size.width; // Use collectionView width
        CGFloat height = 70;
    return CGSizeMake(200, height);
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    // Reset the background color of previously selected cell
    UICollectionViewCell *previousCell = [collectionView cellForItemAtIndexPath:self.selectedIndexPath];
    previousCell.backgroundColor = [UIColor clearColor];

    // Set the background color of the selected cell
    UICollectionViewCell *selectedCell = [collectionView cellForItemAtIndexPath:indexPath];
    selectedCell.backgroundColor = [UIColor lightGrayColor]; // Set your desired background color

    // Update the selectedIndexPath
    _selectedIndexPath = indexPath;
    _selectedAccount = _accountManagement.accounts[indexPath.row];
    
    [_name setText:_selectedAccount.name.value];
    [_email setText:_selectedAccount.email.value];
    [_birthdate setText:_selectedAccount.birthDate.value];
    [_phoneNumber setText:_selectedAccount.phoneNumber.value];
    [_address setText:_selectedAccount.address];
    [_editProfile setTitle:@"Edit Profile" forState:UIControlStateNormal];
}


@end
