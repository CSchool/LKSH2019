import java.io.*;
import java.util.*;

public class feed_av_oc2 {

	FastScanner in;
	PrintWriter out;

	long solve(int a, int b, int c) {
		int ans = 0;
		for (int giveA = 0; giveA <= c; giveA++) {
			for (int giveB = 0; giveA + giveB <= c; giveB++) {
				if (a + giveA > b + giveB) {
					ans++;
				}
			}
		}
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
		new feed_av_oc2().run();
	}
}
