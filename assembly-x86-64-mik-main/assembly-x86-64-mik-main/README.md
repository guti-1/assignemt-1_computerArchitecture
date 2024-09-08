[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mlVCvtKh)
# Mandatory assignment
## x86_64 assembly, beat the compiler

Inf-2200 at UiT The Arctic University of Norway.

This is a group assignment, to be done in groups of two. You need to select a partner in your colloquium group.

The design review dates, and hand-in time are on the course website.

## Detailed description

In this first assignment, you will compare your assembly coding skills against a compiler's. To do this, you will implement a microbenchmark in C and x86 assembly and then compare their performance: 

1. **Select a program to create a microbenchmark**. A microbenchmark is a simplified version of a larger program, often containing only the main loop. It should however be realistic and therefore represent a real program. It should also be relevant and stress, in this case, the CPU. The microbenchmark should, therefore, be CPU-bound and not I/O bound. It should also be repeatable. Two executions should produce the same results. To simplify the assignment, you should select a single-threaded microbenchmark, and you do not want to use floating point operations. Note that you must also get or create a realistic dataset for your microbenchmark.
2. **Identify the main hotspot** in the microbenchmark. This will be the portion of the code you will implement in assembly. A hotspot is where, in the benchmark, most of the execution time is spent. It is likely to be the main loop in the program. It can also be a function called from the main loop. Reimplement a simplified version of the main loop in C to make the following steps easier. You must use a profiler to find the hotspot.
3. **Implement the main loop in assembly**. Also, write C-code to necessary data structures for your function, call your function, and test the results of your function for correctness.
4. **Estimate the theoretical time for execution of your microbenchmark**.
5. **Measure the time for your assembly function and C function**.
6. **Write/produce a report with your findings**.

## Running the assignment in `docker`
A docker environment is available for anyone having problems compiling/running the code due to their system configuration.

Requirements:
 - `Docker` [Download docker here](https://docs.docker.com/get-docker/)
 - `Docker-compose` [Download docker-compose here](https://docs.docker.com/compose/install/)

The environment is available through the command `make docker` when installed. You can compile and run the code as intended when inside the docker environment. All changes in the src folder are registered in the docker environment, you are free to edit the code as usual

## Useful resources
1. [Introduction to Assembly](Introduction_to_Assembly.pdf)

## Deliverables

You should use the pre-code in GitHub as a starting point. We will provide you with a link to the assignment to create a repository for your group. You will also hand in the report by committing it to your GitHub repository before the deadline. The final repository should contain the following:
1. Code
  1. In a directory named “src”, containing code, Makefiles, READMEs etc
  2. NO compiled files. Delete executables, etc., before you hand in.
  3. README must contain how to compile and run the code
2. Report that enables an expert reader to reproduce your results.
   1. In a directory named “doc”, containing report.pdf
   2. Maximum 6 pages
   3. One report per group

The code should:
1. Compile without errors and warnings. 
2. Be structured and clean.
3. Be well commented, such that we understand what your code is doing, and show that you understand your own work.

## The report and possible use of ChatGPT

The report should contain all necessary information for an expert to evaluate your design and implementation. You should assume that the expert has read the textbook and the assignment text. You do not need, and should not, repaeat the content in the textbook. It should have the following sections:
1. Cover page: your names, emails, GitHub usernames, and your GitHub repository.
2. Introduction: description of your benchmark. Why did you choose this benchmark? What does it do? Where is it used?
3. Implementation: describe your assembly (and C) implementation of the microbenchmark. Do not include full code in report, but describe the most relevant or interesting aspects, such as expensive assembly instructions.
4. Methodology, where you describe:
   1. How you measured hotspots
   2. The computer(s) you used for the experiments.
   3. How you measured the execution time for the benchmark, including the resolution of your timer. 
   4.	Experiment parameters such as input data content and size, number of iterations, number of repeated experiment executions, and so on.
5. Results: where you estimate the best theoretical execution time for your benchmark on your computer, and then compare it to the assembly code execution time, and the reference C code execution time.
6. Discussion: where you discuss your results and summarize lessons learned.
7. ChatGPT declaration: where you describe how you have used ChatGPT (or something similar) to help writing your report. You must write this section yourself without the help of ChatGPT.

You may use ChatGPT (or something similar) to improve your report, but you are responsible for the content of the report and you need to declare how you use ChatGPT. It is up to you to find the best use of ChatGPT. Some of our suggestions are: get structure of an IMRaD report, improve language of sections you have written, suggest bakground material description, and get feedback of your results description.

## Cheating

In **Norwegian:** Som student plikter du å sette deg inn i reglene som gjelder for bruk av hjelpemiddel ved eksamen samt regler for kildebruk og sitering. Ved brudd på disse reglene kan du bli mistenkt for fusk eller forsøk på fusk. Fusk på eksamen og plagiering i skriftlige arbeider innebærer at man bryter med det man kaller akademisk redelighet. Akademisk redelighet dreier seg om å være tydelig i forhold til hvilke tanker og refleksjoner som er ens egne og hvilke som er hentet fra andres arbeider, slik at arbeidet kan etterprøves. Fusk er alvorlig og straffes med annullering av eksamen og/eller utestenging fra universitetet. Bruk tid på å sette deg inn hva som regnes som plagiering eller fusk. Instituttets web-side [Kildebruk, plagiering og fusk på eksamen / obligatoriske oppgaver](https://uit.instructure.com/courses/327/pages/kildebruk-plagiering-og-fusk-pa-eksamen-slash-obligatoriske-oppgaver) er en god start for å lære mer om dette.

In **English**: As a student at UiT, you are obliged to familiarize yourself with the current rules that apply to the use of aids during exams, as well as rules for source use and citation. In the case of violation of these rules, you may be suspected of cheating, or attempt at cheating. Cheating on an exam is considered a violation of academic integrity. Academic integrity(honesty) is about being clear in relation to which thoughts/reflection and work are one's own, and which are taken from other's work. Cheating is punishable by cancellation of exams and/or exclusion from university. You can read more about plagiarism and cheating on: [canvas](https://uit.instructure.com/courses/327/pages/kildebruk-plagiering-og-fusk-pa-eksamen-slash-obligatoriske-oppgaver).
