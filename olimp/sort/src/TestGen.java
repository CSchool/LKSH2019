import java.io.*;
import java.util.*;

public class TestGen {
	public static void main(String[] args) throws IOException {
		new TestGen().run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	int tNumber;
	Random rnd;
	final int MAXN = 100;
	ArrayList<Integer> test;
	
	
	void print(ArrayList al) throws IOException {
		System.err.println(tNumber);
		if (tNumber < 10) {
			out = new PrintWriter("../tests/0" + tNumber);
		} else {
			out = new PrintWriter("../tests/" + tNumber);
		}
		tNumber++;
		out.println(al.size());
		for (int i = 0; i < al.size() - 1; i++) {
			out.print(al.get(i) + " ");
		}
		out.println(al.get(al.size() - 1));
		out.close();
		al.clear();
	}
	
	// here starts gens
	
	void gen_sample() throws IOException {
		test.add(2);
		test.add(3);
		test.add(1);
	}
	void gen_simple(int n) throws IOException {
		for(int i = 1; i <= n; i++)
			test.add(i);
	}
	
	void gen_reverse(int n) throws IOException {
		for(int i = n; i > 0; i--)
			test.add(i);
	}
	
	void gen_strange(int n) throws IOException {
		for(int i = 1; i <= n / 2; i++){
			test.add(i);
			test.add(n - i + 1);
		}
		if(n % 2 == 1)
			test.add(n / 2 + 1);
	}
	
	void gen_wat(int n) throws IOException {
		for(int i = 1; i <= n; i++) {
			if(i % 2 == 1)
				test.add(n - i + 1 - (n + 1) % 2);
			else
				test.add(i);
		}
	}
	
	void gen_wat_reverse(int n) throws IOException {
		for(int i = 1; i <= n; i++) {
			if(i % 2 == 0)
				test.add(n - i + 1);
			else
				test.add(i + (n + 1) % 2);
		}
	}
	
	
	void gen_best() throws IOException {
	  test.add(1);
	}
	
	void gen_solvekiller(int n) throws IOException {
		int[] was = new int[n];
		for(int i = 0; i < n; i++) {
			was[i] = 0;
		}
		for(int i = 0; i < n / 2; i++) {
			int number = rnd.nextInt(n);
			while(was[number] == 1) {
				number = rnd.nextInt(n);
			}
			test.add(number + 1);
			was[number] = 1;
		}
		for(int i = 0; i < n; i++)
			if(was[i] == 0)
				test.add(i + 1);
	}
	
	void gen_random(int n) throws IOException {
		int[] was = new int[n];
		for(int i = 0; i < n; i++) {
			was[i] = 0;
		}
		for(int i = 0; i < n; i++) {
			int number = rnd.nextInt(n);
			while(was[number] == 1) {
				number = rnd.nextInt(n);
			}
			test.add(number + 1);
			was[number] = 1;
		}
	}
	
	//the end of the gens
	

	public void generate() throws IOException {
		new File("../tests").mkdir();
		tNumber = 1;
		test = new ArrayList<Integer>();
		rnd = new Random(1234567);
		
		System.err.println("Working...");
		gen_sample();
		print(test);
		//test = new ArrayList<Integer>();
		gen_simple(5);
		print(test);
		gen_best();
		print(test);
		gen_reverse(8);
		print(test);
		gen_strange(11);
		print(test);
		gen_wat(13);
		print(test);
		gen_wat_reverse(14);
		print(test);
		
		System.err.println("Don't panic! Working...");
		
		for(int i = 0; i < 3; i++) {
			gen_simple(rnd.nextInt((i + 2) * 10) + 10);
			print(test);
			gen_reverse(rnd.nextInt((i + 2) * 10) + 10);
			print(test);
			gen_strange(rnd.nextInt((i + 2) * 10) + 10);
			print(test);
			gen_wat(((i + 2) * 10) + 10);
			print(test);
			gen_wat_reverse(((i + 2) * 10) + 10);
			print(test);
			gen_solvekiller(rnd.nextInt((i + 2) * 10) + 10);
			print(test);
			gen_random(rnd.nextInt((i + 2) * 10) + 10);
			print(test);
		}	
		System.err.println("Don't panic! :) Working...");
		gen_simple(100);
		print(test);
		gen_reverse(100);
		print(test);
		gen_strange(100);
		print(test);
		gen_wat(100);
		print(test);
		gen_wat_reverse(100);
		print(test);
		gen_solvekiller(100);
		print(test);
		gen_random(100);
		print(test);
		for(int i = 0; i < 8; i++) {
			gen_solvekiller(rnd.nextInt(50) + 50);
			print(test);
			gen_random(rnd.nextInt(50) + 50);
			print(test);
		}
		
	}

	public void run() throws IOException {
		Locale.setDefault(Locale.US);
		generate();
	}
}
