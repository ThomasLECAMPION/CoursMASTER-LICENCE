package dictionary;

public class OrderedDictionary extends AbstractDictionary
{
    public OrderedDictionary()
    {
        super(keys, values);
    }

    @Override
    private int size()
    {
        return this.keys.length;
    }

    @Override
    private int indexOf(Object key)
    {
        for(int i=0; i<size(); i++)
        {
            if(keys[i].equals(key))
            {
                return i;
            }
        }
    }

    @Override
    private int newIndexOf(Object key)
    {
        Object[] newKeys = new Object[size() + 1];
        Object[] newValues = new Object[size() + 1];

        for(int i=0; i<size(); i++)
        {
            newKeys[i] = this.keys[i];
            newValues[i] = this.values[i];
        }

        this.keys = newKeys;
        this.values = newValues;

        return size();
    }
}
