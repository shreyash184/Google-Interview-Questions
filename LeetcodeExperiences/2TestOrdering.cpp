// You want to run two tests on a device. 
// Each test has a series of setup tests that must be done in order.
// For example,
// you need to complete Step A, B, and C in that order to run test1.
// Then there is test2, which needs steps X, B, and Z to be setup in that order to run.
// You could setup the device by doing the steps like this A, B, C, X, B Z. 
// But that would be inefficient because you are doing step B twice. 
// How would you make the list of steps such that there are no duplicate steps but the order of the steps is maintained. 
// For example, in this case, the optimized correct steps are A, X, B, C,Z.