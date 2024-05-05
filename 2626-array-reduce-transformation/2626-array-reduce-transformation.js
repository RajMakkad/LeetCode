var reduce = function(nums, fn, init) {
  return nums.reduce((acc, element) => fn(acc, element), init);
};