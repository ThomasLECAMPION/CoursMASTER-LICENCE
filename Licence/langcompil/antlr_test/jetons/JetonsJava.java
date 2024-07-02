// Generated from JetonsJava.g4 by ANTLR 4.9.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class JetonsJava extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		OPERATEUR=1, MOTCLE=2, IDENTIFIANT=3, WHITE_SPACE=4, UNMATCH=5;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"OPERATEUR", "MOTCLE", "IDENTIFIANT", "WHITE_SPACE", "UNMATCH"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "OPERATEUR", "MOTCLE", "IDENTIFIANT", "WHITE_SPACE", "UNMATCH"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public JetonsJava(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "JetonsJava.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 0:
			OPERATEUR_action((RuleContext)_localctx, actionIndex);
			break;
		case 1:
			MOTCLE_action((RuleContext)_localctx, actionIndex);
			break;
		case 2:
			IDENTIFIANT_action((RuleContext)_localctx, actionIndex);
			break;
		case 3:
			WHITE_SPACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 4:
			UNMATCH_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void OPERATEUR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			 System.out.print(getText()); 
			break;
		}
	}
	private void MOTCLE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			 System.out.print("[motclé : "+getText()+" ]"); 
			break;
		}
	}
	private void IDENTIFIANT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			 System.out.print("[ident : "+getText()+" ]"); 
			break;
		}
	}
	private void WHITE_SPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			 System.out.print(getText()); 
			break;
		}
	}
	private void UNMATCH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 System.out.print(getText()); 
			break;
		}
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\7`\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\5\2\30\n\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3J"+
		"\n\3\3\3\3\3\3\4\3\4\7\4P\n\4\f\4\16\4S\13\4\3\4\3\4\3\5\6\5X\n\5\r\5"+
		"\16\5Y\3\5\3\5\3\6\3\6\3\6\2\2\7\3\3\5\4\7\5\t\6\13\7\3\2\5\5\2C\\aac"+
		"|\6\2\62;C\\aac|\5\2\13\f\17\17\"\"\2n\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2"+
		"\2\2\2\t\3\2\2\2\2\13\3\2\2\2\3\27\3\2\2\2\5I\3\2\2\2\7M\3\2\2\2\tW\3"+
		"\2\2\2\13]\3\2\2\2\r\30\7>\2\2\16\17\7>\2\2\17\30\7?\2\2\20\30\7@\2\2"+
		"\21\22\7@\2\2\22\30\7?\2\2\23\24\7?\2\2\24\30\7?\2\2\25\26\7#\2\2\26\30"+
		"\7?\2\2\27\r\3\2\2\2\27\16\3\2\2\2\27\20\3\2\2\2\27\21\3\2\2\2\27\23\3"+
		"\2\2\2\27\25\3\2\2\2\30\31\3\2\2\2\31\32\b\2\2\2\32\4\3\2\2\2\33\34\7"+
		"d\2\2\34\35\7t\2\2\35\36\7g\2\2\36\37\7c\2\2\37J\7m\2\2 !\7e\2\2!\"\7"+
		"n\2\2\"#\7c\2\2#$\7u\2\2$J\7u\2\2%&\7f\2\2&\'\7q\2\2\'(\7w\2\2()\7d\2"+
		"\2)*\7n\2\2*J\7g\2\2+,\7g\2\2,-\7n\2\2-.\7u\2\2.J\7g\2\2/\60\7k\2\2\60"+
		"J\7h\2\2\61\62\7k\2\2\62\63\7o\2\2\63\64\7r\2\2\64\65\7q\2\2\65\66\7t"+
		"\2\2\66J\7v\2\2\678\7r\2\289\7w\2\29:\7d\2\2:;\7n\2\2;<\7k\2\2<J\7e\2"+
		"\2=>\7u\2\2>?\7v\2\2?@\7c\2\2@A\7v\2\2AB\7k\2\2BJ\7e\2\2CD\7v\2\2DE\7"+
		"j\2\2EF\7t\2\2FG\7q\2\2GH\7y\2\2HJ\7u\2\2I\33\3\2\2\2I \3\2\2\2I%\3\2"+
		"\2\2I+\3\2\2\2I/\3\2\2\2I\61\3\2\2\2I\67\3\2\2\2I=\3\2\2\2IC\3\2\2\2J"+
		"K\3\2\2\2KL\b\3\3\2L\6\3\2\2\2MQ\t\2\2\2NP\t\3\2\2ON\3\2\2\2PS\3\2\2\2"+
		"QO\3\2\2\2QR\3\2\2\2RT\3\2\2\2SQ\3\2\2\2TU\b\4\4\2U\b\3\2\2\2VX\t\4\2"+
		"\2WV\3\2\2\2XY\3\2\2\2YW\3\2\2\2YZ\3\2\2\2Z[\3\2\2\2[\\\b\5\5\2\\\n\3"+
		"\2\2\2]^\13\2\2\2^_\b\6\6\2_\f\3\2\2\2\7\2\27IQY\7\3\2\2\3\3\3\3\4\4\3"+
		"\5\5\3\6\6";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}