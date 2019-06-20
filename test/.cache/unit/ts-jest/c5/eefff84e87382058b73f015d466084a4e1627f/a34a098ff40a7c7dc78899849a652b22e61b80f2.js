"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const util_1 = require("util");
exports.missingArgs = (...params) => params.some(param => util_1.isUndefined(param));
exports.result = (func) => {
    const result = {};
    try {
        func();
    }
    catch (err) {
    }
    //Reflect.defineMetadata();
};
const head = (as) => {
    if (as.length === 0) {
        throw new Error('Empty array');
    }
    return as[0];
};
/*   let s: string
  try {
    s = String(head([]))
  } catch (e) {
    s = e.message
  } */ 
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJmaWxlIjoiL2hvbWUvam0vUHJvamVjdHMvTW9kdWxlcy9jb21tb24vc3JjL2Z1bmN0aW9uYWwvZnVuY3Rpb24tdXRpbHMudHMiLCJtYXBwaW5ncyI6Ijs7QUFBQSwrQkFBbUM7QUFHdEIsUUFBQSxXQUFXLEdBQUcsQ0FBVSxHQUFHLE1BQVcsRUFBRSxFQUFFLENBQUMsTUFBTSxDQUFDLElBQUksQ0FBQyxLQUFLLENBQUMsRUFBRSxDQUFDLGtCQUFXLENBQUMsS0FBSyxDQUFDLENBQUMsQ0FBQztBQUVwRixRQUFBLE1BQU0sR0FBRyxDQUFTLElBQUksRUFBRSxFQUFFO0lBQ25DLE1BQU0sTUFBTSxHQUFHLEVBQUUsQ0FBQTtJQUNqQixJQUFJO1FBQ0EsSUFBSSxFQUFFLENBQUE7S0FDVDtJQUFDLE9BQU0sR0FBRyxFQUFDO0tBRVg7SUFDRCwyQkFBMkI7QUFDL0IsQ0FBQyxDQUFBO0FBRUQsTUFBTSxJQUFJLEdBQUcsQ0FBSSxFQUFZLEVBQUssRUFBRTtJQUNoQyxJQUFJLEVBQUUsQ0FBQyxNQUFNLEtBQUssQ0FBQyxFQUFFO1FBQ25CLE1BQU0sSUFBSSxLQUFLLENBQUMsYUFBYSxDQUFDLENBQUE7S0FDL0I7SUFDRCxPQUFPLEVBQUUsQ0FBQyxDQUFDLENBQUMsQ0FBQTtBQUNkLENBQUMsQ0FBQTtBQUVIOzs7OztNQUtNIiwibmFtZXMiOltdLCJzb3VyY2VzIjpbIi9ob21lL2ptL1Byb2plY3RzL01vZHVsZXMvY29tbW9uL3NyYy9mdW5jdGlvbmFsL2Z1bmN0aW9uLXV0aWxzLnRzIl0sInNvdXJjZXNDb250ZW50IjpbImltcG9ydCB7IGlzVW5kZWZpbmVkIH0gZnJvbSBcInV0aWxcIjtcblxuIFxuZXhwb3J0IGNvbnN0IG1pc3NpbmdBcmdzID0gPFQgPSBhbnk+KC4uLnBhcmFtczogVFtdKSA9PiBwYXJhbXMuc29tZShwYXJhbSA9PiBpc1VuZGVmaW5lZChwYXJhbSkpO1xuXG5leHBvcnQgY29uc3QgcmVzdWx0ID0gPFQ9IGFueT4oZnVuYykgPT4ge1xuICAgIGNvbnN0IHJlc3VsdCA9IHt9XG4gICAgdHJ5IHtcbiAgICAgICAgZnVuYygpXG4gICAgfSBjYXRjaChlcnIpe1xuXG4gICAgfVxuICAgIC8vUmVmbGVjdC5kZWZpbmVNZXRhZGF0YSgpO1xufVxuXG5jb25zdCBoZWFkID0gPEE+KGFzOiBBcnJheTxBPik6IEEgPT4ge1xuICAgIGlmIChhcy5sZW5ndGggPT09IDApIHtcbiAgICAgIHRocm93IG5ldyBFcnJvcignRW1wdHkgYXJyYXknKVxuICAgIH1cbiAgICByZXR1cm4gYXNbMF1cbiAgfVxuICBcbi8qICAgbGV0IHM6IHN0cmluZ1xuICB0cnkge1xuICAgIHMgPSBTdHJpbmcoaGVhZChbXSkpXG4gIH0gY2F0Y2ggKGUpIHtcbiAgICBzID0gZS5tZXNzYWdlXG4gIH0gKi8iXSwidmVyc2lvbiI6M30=