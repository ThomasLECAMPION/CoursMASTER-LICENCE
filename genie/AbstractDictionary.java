package dictionary;

public abstract class AbstractDictionary implements IDictionary
{
    public AbstractDictionary()
    {
        private Object[] keys;
        private Object[] values;
    }

    public Object get(Object key)
    {
        if(indexOf(key) != -1) return this.values[indexOf(key)];
    }
private abstract int indexOf(Object key);
    private abstract int newIndexOf(Object key);
    public IDictionary put(Object key, Object value)
    {
        if(indexOf(key) == -1)
        {
            int newIndex = newIndexOf(key);
            keys[newIndex] = key;
            values[newIndex] = value;
        }
        return this;
    }

    public boolean isEmpty()
    {
        if(this.keys.length == 0) return true;
        else return false;
    }

    public boolean containsKey(Object key)
    {
        if(indexOf(key) == -1) return false;
        else return true;
    }

    private abstract int indexOf(Object key);
    private abstract int newIndexOf(Object key);
    private abstract int size();
}
