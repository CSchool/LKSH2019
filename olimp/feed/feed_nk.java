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

public class feed_nk {

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


	public long sum(long s, long f){
		if (s  < 0 ||  f < 0)
			return 0;
		return (f-s + 1) * (s+f)/2;
	}
	
	public void solve() throws IOException {
		in = new BufferedReader(new FileReader("feed.in"));
		out = new PrintWriter("feed.out");
		long a = nextLong();
		long b = nextLong();
		long c = nextLong();
		if (b >= a){
			c -= b-a + 1;
			a = b + 1;
		}
		if (c < 0){
			out.println(0);
			out.close();
			return;
		}
		long t = sum (Math.max(c - (a-b) + 2, 0), c+1);
		//out.println(t);
		long beg = (c - (a - b)) % 2;
		long end = c - (a - b);
		
		out.print(t + sum(beg, end) * ((end - beg)/2 + 1)/(end - beg + 1));
	
		out.close();
	}

	static void myAssert(boolean b, String string) {
		if (!b) {
			throw new AssertionError(string);
		}
	}

	public static void main(String[] args) throws IOException {
		new feed_nk().solve();
	}
}