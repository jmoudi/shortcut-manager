 
export const createID = () => Date.now() + Math.floor(100000*Math.random());

export const toChar = (code: number) => String.fromCharCode.call(null, code);

export const normalize = (key) => toUpper(key);
