IEnumerator<int> TestIteratorMethod()
{
	yield return 1;
	yield return 2;
	yield return 3;
	yield return 4;
	yield return 5;
	yield return 6;
	yield return 7;
	yield return 8;
	yield return 9;
	yield return 10;
}

IEnumerator<int> enumerator = TestIteratorMethod();

while(enumerator.MoveNext())
{
	Console.WriteLine(enumerator.Current);
}
