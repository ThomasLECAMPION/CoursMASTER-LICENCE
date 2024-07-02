package dictionary;

public class UtilisationDictionnaire
{
    public static void main(String[] args)
    {
        static IDictionary dic;
        dic = new OrderedDictionary();

        dic.put("Charles","OH");

        /*
        public abstract Object get(Object key);
        public abstract IDictionary put(Object key, Object value);
        public abstract boolean isEmpty();
        public abstract boolean containsKey(Object key);
        public abstract int size();
        */
    }
}
