//
//  WDArithmeticOCManager.m
//  WDArithmetic
//
//  Created by 伟东 on 2020/12/23.
//

#import "WDArithmeticOCManager.h"

@implementation WDArithmeticOCManager

//----------------------------------------------------
//两个很长的数字字符串，计算两个的和(数学加法可能会存在溢出的问题)
- (void)addLongString {
    NSArray *array = [self addNum:@"1234567890987654321" b:@"9991234567899999999"];
    NSMutableString *str = [[NSMutableString alloc] init];
    for (int i = 0; i<array.count; i++) {
        if (i ==0 && [array.firstObject intValue] == 0) {
            continue;
        }
        [str appendString:[[array objectAtIndex:i] stringValue]];
    }
    NSLog(@"%@",str);
}

- (NSArray *)addNum:(NSString *)a b:(NSString *)b {
    
    // 对数字字符串做格式处理 不足位补0
    NSArray *prepare = [self prepare:a b:b];
    
    a = prepare.firstObject;
    b = prepare.lastObject;
    NSLog(@"%@",a);
    NSLog(@"%@",b);

    NSMutableArray *temp = [NSMutableArray array];
    int num = 0;
    int num1 = 0;
    int num2 = 0;
    int len = (int)a.length;
    int j = 1;
    for (int j = 0; j<len+1; j++) {
        [temp addObject:@(0)];
    }
    
    for (int i = len - 1; i>=0; i--) {
        NSRange range = NSMakeRange(i, 1);
        num1 = [a substringWithRange:range].intValue;
        num2 = [b substringWithRange:range].intValue;
        
        num = num1 + num2;
        int count = (int)temp.count;
        num = num + [[temp objectAtIndex:count-j] intValue];
        
        if (count-j-1>=0) {
            [temp replaceObjectAtIndex:count-j  withObject:@(num%10)];
            [temp replaceObjectAtIndex:count-j-1 withObject:@(num/10)];
        }
        j++;
    }
    return temp;
}


- (NSArray *)prepare:(NSString *)a b:(NSString *)b {
    NSMutableArray *temp = [NSMutableArray array];
    if (a.length > b.length) {
        b = [self doFormat:b n:a.length partten:0];
    }else if (a.length < b.length){
        a = [self doFormat:a n:b.length partten:0];
    }
    [temp insertObject:a atIndex:0];
    [temp insertObject:b atIndex:1];
    return temp;
}
- (NSString *)doFormat:(NSString *)str n:(int)n partten:(int)partten {
    NSMutableString *string = [NSMutableString string];
    for (int i = 0; i < n-str.length; i++) {
        [string appendString:[NSString stringWithFormat:@"%d",partten]];
    }
    [string appendString:str];
    
    return string;
}


//----------------------------------------------------
//实现两个NSRange的交集 （0，6）（2，7）
- (void)testRange {
    
//    （0,6）(2,7)
//    (2,7) (0.6)
//    (0,6) (10,3)
//    (10,3) (0,6)
//    (0,100) (3,10)
//    (4,9)(0,100)
    
    NSRange range1 = NSMakeRange(4, 9);
    NSRange range2 = NSMakeRange(0, 100);

    NSRange newRange = [self getIntersectionRangeWithRange1:range1 range2:range2];
    NSLog(@"newRange--location:%lu----length:%lu",(unsigned long)newRange.location,(unsigned long)newRange.length);
    NSRange range = NSIntersectionRange(range1, range2);
    NSLog(@"NSIntersectionRange--location:%lu----length:%lu",(unsigned long)range.location,(unsigned long)range.length);

}


/// 两个range的交集 （0，0）表示没有交集
/// @param range1 range1 description
/// @param range2 range2 description
- (NSRange)getIntersectionRangeWithRange1:(NSRange)range1 range2:(NSRange)range2 {
    
    NSInteger range1_loc = range1.location;
    NSInteger range1_len = range1.length;
    
    NSInteger range2_loc = range2.location;
    NSInteger range2_len = range2.length;
    
    if (!range1_len) {
        return NSMakeRange(0, 0);
    }
    if (!range2_len) {
        return NSMakeRange(0, 0);
    }
    
    
    if (range1_loc + range1_len < range2_loc) {
        return NSMakeRange(0, 0);
    }
    if (range2_loc + range2_len < range1_loc) {
        return NSMakeRange(0, 0);
    }
    
    NSInteger loc = 0;
    NSInteger len = 0;
    if (range1_loc >= range2_loc) {
        loc = range1_loc;
    }else {
        loc = range2_loc;
    }
    
    if (range1_len >= range2_len + range2_loc) {
        len = range2_len + range2_loc - loc;
    }else if (range2_len >= range1_len + range1_loc) {
        len = range1_len + range1_loc - loc;
    }else if (range1_len >= range2_len) {
        len = range2_len - loc;
    }else if (range2_len >= range1_len) {
        len = range1_len - loc;
    }else{
        len = range1_len;
    }
    
    NSRange newRange = NSMakeRange(loc, len);
    return newRange;
}






@end
