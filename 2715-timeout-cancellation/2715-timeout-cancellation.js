var cancellable = function(fn, args, t) {
    const cancel = () => clearTimeout(timer);
    const timer = setTimeout(() => fn(...args), t);
    return cancel;
};
