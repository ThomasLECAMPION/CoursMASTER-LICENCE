#!/bin/sh
export CLASSPATH=".:/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH"
export CLASSPATH=".:/usr/local/lib/antlr-runtime-4.7.2-complete.jar:$CLASSPATH"
alias antlr4='java -Xmx500M -cp "/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH" org.antlr.v4.Tool'
alias grun4='java -Xmx500M -cp "/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH" org.antlr.v4.gui.TestRig'

antlr4 Calculette.g4 &&
javac Calculette*.java &&
java MainCalculette > Calculette.mvap &&
java -cp "/usr/share/java/*:MVaP.jar" MVaPAssembler Calculette.mvap &&
java -jar MVaP.jar Calculette.mvap.cbap