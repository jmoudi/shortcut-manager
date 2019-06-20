"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
/*
function formatErrorMessage1<T = Error>(err: T){
    return [
        `${errConstructor.name}:   ${type}`,
        `${message}`,
        `passed Arguments: ${args}`
    ].join(`\n`)
} */
const format = (type, message, ...args) => {
    return [
        `ERROR:   ${type}`,
        `${message}`,
        `passed Arguments:`,
        ...args,
    ].join(`\n`);
};
function createError(type, message, ...args) {
    return new Error(format(type, message, ...args));
}
exports.createError = createError;
function formatErrorMessage(err) {
    return ``;
    /*     const lines = [
            `${name}:   ${type}`,
            `${message}`,
            `passed Arguments: ${args}`
        ]
        )
    }
    {
        type: err.name,
        message: err.messagel
        trace: err. */
}
exports.formatErrorMessage = formatErrorMessage;
function logError({ type, message, args }) {
    return new Error(`ERROR: ${type}
    ${message}
    Arguments: ${args}`);
}
exports.logError = logError;
function raiseError(init) {
    //Object.getPrototypeOf(err).name
    let err;
    const errConstructor = Error;
    if (typeof init === 'string') {
        err = new Error(init);
        Object.getPrototypeOf(err);
    }
    if (typeof init === 'object') {
        const { type, message, args } = init;
        function formatErrorMessage(err) {
            return [
                `${errConstructor.name}:   ${type}`,
                `${message}`,
                `passed Arguments: ${args}`
            ].join(`\n`);
        }
    }
}
exports.raiseError = raiseError;
/*         )
        }
        err = new Error(formatErrorMessage());
        err.type = init.type;
        err.arguments = init.arguments;

    }
    return new Error(`ERROR: ${type}
    ${message}
    Arguments: ${args}`) */
/* export function createError<T = any>({ type, message, args }: ErrorInit){
    return new Error(`ERROR: ${type}
    ${message}
    Arguments: ${args}`)
} */ 
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJmaWxlIjoiL2hvbWUvam0vUHJvamVjdHMvTW9kdWxlcy9jb21tb24vc3JjL2Z1bmN0aW9uYWwvZXJyb3IudHMiLCJtYXBwaW5ncyI6Ijs7QUFRQTs7Ozs7OztJQU9JO0FBQ0osTUFBTSxNQUFNLEdBQUcsQ0FBa0IsSUFBSSxFQUFFLE9BQU8sRUFBRSxHQUFHLElBQUksRUFBRSxFQUFFO0lBQ3ZELE9BQU87UUFDSCxZQUFZLElBQUksRUFBRTtRQUNsQixHQUFHLE9BQU8sRUFBRTtRQUNaLG1CQUFtQjtRQUNuQixHQUFHLElBQUk7S0FDVixDQUFDLElBQUksQ0FBQyxJQUFJLENBQUMsQ0FBQTtBQUNoQixDQUFDLENBQUE7QUFFRCxTQUFnQixXQUFXLENBQVUsSUFBZSxFQUFFLE9BQWdCLEVBQUUsR0FBRyxJQUFVO0lBQ2pGLE9BQU8sSUFBSSxLQUFLLENBQUMsTUFBTSxDQUFDLElBQUksRUFBRSxPQUFPLEVBQUUsR0FBRyxJQUFJLENBQUMsQ0FBQyxDQUFDO0FBRXJELENBQUM7QUFIRCxrQ0FHQztBQUlELFNBQWdCLGtCQUFrQixDQUFZLEdBQU07SUFBRyxPQUFPLEVBQUUsQ0FBQTtJQUNoRTs7Ozs7Ozs7OztzQkFVa0I7QUFDbEIsQ0FBQztBQVpELGdEQVlDO0FBQ0QsU0FBZ0IsUUFBUSxDQUFVLEVBQUUsSUFBSSxFQUFFLE9BQU8sRUFBRSxJQUFJLEVBQWE7SUFDaEUsT0FBTyxJQUFJLEtBQUssQ0FBQyxVQUFVLElBQUk7TUFDN0IsT0FBTztpQkFDSSxJQUFJLEVBQUUsQ0FBQyxDQUFBO0FBQ3hCLENBQUM7QUFKRCw0QkFJQztBQUNELFNBQWdCLFVBQVUsQ0FBVSxJQUFxQjtJQUNyRCxpQ0FBaUM7SUFDakMsSUFBSSxHQUFHLENBQUM7SUFDUixNQUFNLGNBQWMsR0FBRyxLQUFLLENBQUE7SUFDNUIsSUFBSSxPQUFPLElBQUksS0FBSyxRQUFRLEVBQUM7UUFDekIsR0FBRyxHQUFHLElBQUksS0FBSyxDQUFDLElBQUksQ0FBQyxDQUFDO1FBQUMsTUFBTSxDQUFDLGNBQWMsQ0FBQyxHQUFHLENBQUMsQ0FBQTtLQUNwRDtJQUNELElBQUksT0FBTyxJQUFJLEtBQUssUUFBUSxFQUFDO1FBQ3pCLE1BQU0sRUFBRSxJQUFJLEVBQUUsT0FBTyxFQUFFLElBQUksRUFBRSxHQUFHLElBQUksQ0FBQztRQUNyQyxTQUFTLGtCQUFrQixDQUFZLEdBQU07WUFDekMsT0FBTztnQkFDSCxHQUFHLGNBQWMsQ0FBQyxJQUFJLE9BQU8sSUFBSSxFQUFFO2dCQUNuQyxHQUFHLE9BQU8sRUFBRTtnQkFDWixxQkFBcUIsSUFBSSxFQUFFO2FBQzlCLENBQUMsSUFBSSxDQUFDLElBQUksQ0FBQyxDQUFBO1FBQ2hCLENBQUM7S0FDSjtBQUNMLENBQUM7QUFqQkQsZ0NBaUJDO0FBQ0Q7Ozs7Ozs7OzsyQkFTMkI7QUFFM0I7Ozs7SUFJSSIsIm5hbWVzIjpbXSwic291cmNlcyI6WyIvaG9tZS9qbS9Qcm9qZWN0cy9Nb2R1bGVzL2NvbW1vbi9zcmMvZnVuY3Rpb25hbC9lcnJvci50cyJdLCJzb3VyY2VzQ29udGVudCI6WyJcblxudHlwZSBDcmVhdGVFcnJvckluaXQgPSBzdHJpbmcgfCBFcnJvckluaXQ7XG5pbnRlcmZhY2UgRXJyb3JJbml0IHtcblx0dHlwZTogc3RyaW5nO1xuXHRtZXNzYWdlPzogc3RyaW5nO1xuXHRhcmdzPzogYW55W107XG59XG4vKiBcbmZ1bmN0aW9uIGZvcm1hdEVycm9yTWVzc2FnZTE8VCA9IEVycm9yPihlcnI6IFQpe1xuICAgIHJldHVybiBbXG4gICAgICAgIGAke2VyckNvbnN0cnVjdG9yLm5hbWV9OiAgICR7dHlwZX1gLFxuICAgICAgICBgJHttZXNzYWdlfWAsXG4gICAgICAgIGBwYXNzZWQgQXJndW1lbnRzOiAke2FyZ3N9YFxuICAgIF0uam9pbihgXFxuYClcbn0gKi9cbmNvbnN0IGZvcm1hdCA9IDxUIGV4dGVuZHMgRXJyb3I+KHR5cGUsIG1lc3NhZ2UsIC4uLmFyZ3MpID0+IHtcbiAgICByZXR1cm4gW1xuICAgICAgICBgRVJST1I6ICAgJHt0eXBlfWAsXG4gICAgICAgIGAke21lc3NhZ2V9YCxcbiAgICAgICAgYHBhc3NlZCBBcmd1bWVudHM6YCxcbiAgICAgICAgLi4uYXJncyxcbiAgICBdLmpvaW4oYFxcbmApXG59IFxudHlwZSBFcnJvclR5cGUgPSBzdHJpbmd8bnVtYmVyO1xuZXhwb3J0IGZ1bmN0aW9uIGNyZWF0ZUVycm9yPFQgPSBhbnk+KHR5cGU6IEVycm9yVHlwZSwgbWVzc2FnZT86IHN0cmluZywgLi4uYXJnczphbnlbXSl7ICAgIFxuICAgIHJldHVybiBuZXcgRXJyb3IoZm9ybWF0KHR5cGUsIG1lc3NhZ2UsIC4uLmFyZ3MpKTtcbiAgICBcbn1cbiBcblxuXG5leHBvcnQgZnVuY3Rpb24gZm9ybWF0RXJyb3JNZXNzYWdlPFQgPSBFcnJvcj4oZXJyOiBUKXsgcmV0dXJuIGBgXG4vKiAgICAgY29uc3QgbGluZXMgPSBbXG4gICAgICAgIGAke25hbWV9OiAgICR7dHlwZX1gLFxuICAgICAgICBgJHttZXNzYWdlfWAsXG4gICAgICAgIGBwYXNzZWQgQXJndW1lbnRzOiAke2FyZ3N9YFxuICAgIF1cbiAgICApXG59XG57IFxuICAgIHR5cGU6IGVyci5uYW1lLFxuICAgIG1lc3NhZ2U6IGVyci5tZXNzYWdlbFxuICAgIHRyYWNlOiBlcnIuICovXG59XG5leHBvcnQgZnVuY3Rpb24gbG9nRXJyb3I8VCA9IGFueT4oeyB0eXBlLCBtZXNzYWdlLCBhcmdzIH06IEVycm9ySW5pdCl7XG4gICAgcmV0dXJuIG5ldyBFcnJvcihgRVJST1I6ICR7dHlwZX1cbiAgICAke21lc3NhZ2V9XG4gICAgQXJndW1lbnRzOiAke2FyZ3N9YClcbn1cbmV4cG9ydCBmdW5jdGlvbiByYWlzZUVycm9yPFQgPSBhbnk+KGluaXQ6IENyZWF0ZUVycm9ySW5pdCl7XG4gICAgLy9PYmplY3QuZ2V0UHJvdG90eXBlT2YoZXJyKS5uYW1lXG4gICAgbGV0IGVycjtcbiAgICBjb25zdCBlcnJDb25zdHJ1Y3RvciA9IEVycm9yXG4gICAgaWYgKHR5cGVvZiBpbml0ID09PSAnc3RyaW5nJyl7XG4gICAgICAgIGVyciA9IG5ldyBFcnJvcihpbml0KTsgT2JqZWN0LmdldFByb3RvdHlwZU9mKGVycilcbiAgICB9XG4gICAgaWYgKHR5cGVvZiBpbml0ID09PSAnb2JqZWN0Jyl7XG4gICAgICAgIGNvbnN0IHsgdHlwZSwgbWVzc2FnZSwgYXJncyB9ID0gaW5pdDtcbiAgICAgICAgZnVuY3Rpb24gZm9ybWF0RXJyb3JNZXNzYWdlPFQgPSBFcnJvcj4oZXJyOiBUKXtcbiAgICAgICAgICAgIHJldHVybiBbXG4gICAgICAgICAgICAgICAgYCR7ZXJyQ29uc3RydWN0b3IubmFtZX06ICAgJHt0eXBlfWAsXG4gICAgICAgICAgICAgICAgYCR7bWVzc2FnZX1gLFxuICAgICAgICAgICAgICAgIGBwYXNzZWQgQXJndW1lbnRzOiAke2FyZ3N9YFxuICAgICAgICAgICAgXS5qb2luKGBcXG5gKVxuICAgICAgICB9XG4gICAgfVxufVxuLyogICAgICAgICApXG4gICAgICAgIH1cbiAgICAgICAgZXJyID0gbmV3IEVycm9yKGZvcm1hdEVycm9yTWVzc2FnZSgpKTtcbiAgICAgICAgZXJyLnR5cGUgPSBpbml0LnR5cGU7XG4gICAgICAgIGVyci5hcmd1bWVudHMgPSBpbml0LmFyZ3VtZW50cztcblxuICAgIH1cbiAgICByZXR1cm4gbmV3IEVycm9yKGBFUlJPUjogJHt0eXBlfVxuICAgICR7bWVzc2FnZX1cbiAgICBBcmd1bWVudHM6ICR7YXJnc31gKSAqL1xuIFxuLyogZXhwb3J0IGZ1bmN0aW9uIGNyZWF0ZUVycm9yPFQgPSBhbnk+KHsgdHlwZSwgbWVzc2FnZSwgYXJncyB9OiBFcnJvckluaXQpe1xuICAgIHJldHVybiBuZXcgRXJyb3IoYEVSUk9SOiAke3R5cGV9XG4gICAgJHttZXNzYWdlfVxuICAgIEFyZ3VtZW50czogJHthcmdzfWApXG59ICovIl0sInZlcnNpb24iOjN9