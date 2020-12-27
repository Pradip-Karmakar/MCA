public static <T> int countAllOccurrences(T[] list, T element) {
int count = 0;
if (element == null) {
for ( T listElement : list )
if (listElement == null)
count++;
}
else {
for ( T listElement : list )
if (element.equals(listElement))
count++;
}
return count;
}