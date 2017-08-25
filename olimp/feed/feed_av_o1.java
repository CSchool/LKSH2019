import java.io.*;
import java.util.*;

public class feed_av_o1 {

	FastScanner in;
	PrintWriter out;

	long solve(int a, int b, int c) {
		int needToAdd = Math.max(0, b - a + 1);
		if (c < needToAdd) {
			return 0;
		}
		c -= needToAdd;
		a += needToAdd;

		int diff = (a - b - 1);

		if (c <= diff) {
			long ans = (long) (c + 2) * (c + 1) / 2;
			return ans;
		}
		long ans = (long) (diff + 2) * (diff + 1) / 2;
		
		int from = diff + 1, to = c;
		
		if ((from + diff) % 2 == 1) {
			ans += (from + diff) / 2 + 1;
			from++;
		}
		
		if ((to + diff) % 2 == 0) {
			ans += (to + diff) / 2 + 1;
			to--;
		}
		
		int count = (to - from + 1) / 2;
		int min = (from + diff) / 2, max = (to + diff) / 2;
		
		ans += 2L * count * (min + max) / 2 + count * 2;
		
		return ans;

	}
	void run() {
		try {
			in = new FastScanner("feed.in");
			out = new PrintWriter("feed.out");
			out.println(solve(in.nextInt(), in.nextInt(), in.nextInt()));
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new feed_av_o1().run();
	}
}
