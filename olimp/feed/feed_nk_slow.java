import java.awt.List;
import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.management.Query;

public class feed_nk_slow {

	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;

	String next() throws IOException {
		String help;
		while ((str == null) || (!str.hasMoreTokens())) {
			help = in.readLine();
			if (help == null) {
				return null;
			}
			str = new StringTokenizer(help);
		}
		return str.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	public long sum(long s, long f) {
		if (s < 0 || f < 0)
			return 0;
		return (f - s + 1) * (s + f) / 2;
	}

	public void solve() throws IOException {
		in = new BufferedReader(new FileReader("feed.in"));
		out = new PrintWriter("feed.out");
		int a = nextInt();
		int b = nextInt();
		int c = nextInt();
		int res = 0;
		for (int i = a; i <= 1000000000; i++) {
			if (i - a > c)
				break;
			for (int j = b; j <= 1000000000; j++) {
				if (i > j && (i - a) + (j - b) <= c)
					res++;
				else
					break;
			}
		}
		out.println(res);
		out.close();
	}

	static void myAssert(boolean b, String string) {
		if (!b) {
			throw new AssertionError(string);
		}
	}

	public static void main(String[] args) throws IOException {
		new feed_nk_slow().solve();
	}
}