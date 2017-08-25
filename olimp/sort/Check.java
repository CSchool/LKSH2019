import ru.ifmo.testlib.*;
import ru.ifmo.testlib.Outcome.Type;

public class Check implements Checker {
    @Override
    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        try {
        int n = inf.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = inf.nextInt();
        }
        int k = ouf.nextInt();
        if (k < 0 || k >= 50000)
            return new Outcome(Type.WA, "Wrong number of operations");
        for(int i = 0; i < k; i++) {
          int ind1 = ouf.nextInt(), ind2 = ouf.nextInt();
          if(ind1 < 1 || ind1 > n || ind2 < 1 || ind2 > n)
            return new Outcome(Type.WA, "Incorrect index");
          ind1--;
          ind2--;
          if(a[ind1] - a[ind2] != 1 && a[ind1] - a[ind2] != -1)
            return new Outcome(Type.WA, "Wrong operation");
          int tmp = a[ind1];
          a[ind1] = a[ind2];
          a[ind2] = tmp;
        }

        for(int i = 0; i < n - 1; i++)
          if(a[i] > a[i + 1])
            return new Outcome(Type.WA, "Wrong order");

        return new Outcome(Type.OK, "OK!");
      } catch (Throwable e) {
            return new Outcome(Type.PE, "Something went wrong!");
      }
    }
}
