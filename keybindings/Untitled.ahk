reviver(this, key, value)
{
	; return value as is if you don't want to alter it
	return [value][1] ; for numeric values, preserve internally cached number
}