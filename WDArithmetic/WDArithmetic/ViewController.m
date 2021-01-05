//
//  ViewController.m
//  WDArithmetic
//
//  Created by 伟东 on 2020/12/16.
//

#import "ViewController.h"
#import "WDArithmeticManager.h"
#import "WDArithmeticOCManager.h"
#import "WDArithmeticLinklistManager.h"
#import "WDOCClang.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
//    quickSort();
//    bubblingSort();
//    selectSort();
//    insertSort();
//    maxHeapifySort();
//    updateArray();
//    canThreePartsEqualSum();
//    arrayCanJump();
    
//    deleteLinkDuplication();
//    sListPrintTailToHead();
//    sListReverse();
//    slistMerge();
//    sListFindMidNode();
//    sListFindTailKNode();
//    sListFindPop();
//    sListIsCrcle();
//    sListCycleLen();
//    sListCrossEntreNode();
//    sListIsCrossNode();
    
    
    WDArithmeticOCManager *oc = [[WDArithmeticOCManager alloc] init];
//    [oc addLongString];
//    [oc testRange];
    
    
    [self testperformSelector];
}


- (void)testperformSelector {
    dispatch_async(dispatch_queue_create(0, 0), ^{
        NSLog(@"1");
        [self performSelector:@selector(test1) withObject:nil afterDelay:.0f];
        [[NSRunLoop currentRunLoop] run];
        NSLog(@"3");
    });
}
- (void)test1 {
    NSLog(@"2");
}



@end
