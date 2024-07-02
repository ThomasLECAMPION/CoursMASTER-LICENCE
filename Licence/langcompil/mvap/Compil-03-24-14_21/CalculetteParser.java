// Generated from Calculette.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class CalculetteParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, TYPE=33, NEWLINE=34, WS=35, ENTIER=36, MULTICOMMENTAIRE=37, 
		SINGLECOMMENTAIRE=38, IDENTIFIANT=39, UNMATCH=40;
	public static final int
		RULE_start = 0, RULE_calcul = 1, RULE_instruction = 2, RULE_fonction = 3, 
		RULE_params = 4, RULE_args = 5, RULE_expression = 6, RULE_finInstruction = 7, 
		RULE_decl = 8, RULE_assignation = 9, RULE_condition = 10, RULE_bloc = 11;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "calcul", "instruction", "fonction", "params", "args", "expression", 
			"finInstruction", "decl", "assignation", "condition", "bloc"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'read'", "'('", "')'", "'write'", "'while'", "'if'", "'else'", 
			"'for'", "';'", "'repeat'", "'until'", "','", "'*'", "'/'", "'+'", "'-'", 
			"'='", "'++'", "'true'", "'false'", "'=='", "'!='", "'<>'", "'<='", "'>='", 
			"'<'", "'>'", "'&&'", "'||'", "'!'", "'{'", "'}'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, "TYPE", "NEWLINE", 
			"WS", "ENTIER", "MULTICOMMENTAIRE", "SINGLECOMMENTAIRE", "IDENTIFIANT", 
			"UNMATCH"
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

	@Override
	public String getGrammarFileName() { return "Calculette.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


	   private TableSymboles tableSymboles = new TableSymboles();
	   private int _cur_label = 1;
	    /** générateur de nom d'étiquettes pour les boucles */
	    private String getNewLabel() { return "b" +(_cur_label++); }

	public CalculetteParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class StartContext extends ParserRuleContext {
		public CalculContext calcul() {
			return getRuleContext(CalculContext.class,0);
		}
		public TerminalNode EOF() { return getToken(CalculetteParser.EOF, 0); }
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterStart(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitStart(this);
		}
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(24);
			calcul();
			setState(25);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CalculContext extends ParserRuleContext {
		public String code;
		public DeclContext decl;
		public InstructionContext instruction;
		public List<DeclContext> decl() {
			return getRuleContexts(DeclContext.class);
		}
		public DeclContext decl(int i) {
			return getRuleContext(DeclContext.class,i);
		}
		public List<TerminalNode> NEWLINE() { return getTokens(CalculetteParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(CalculetteParser.NEWLINE, i);
		}
		public List<InstructionContext> instruction() {
			return getRuleContexts(InstructionContext.class);
		}
		public InstructionContext instruction(int i) {
			return getRuleContext(InstructionContext.class,i);
		}
		public CalculContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_calcul; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterCalcul(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitCalcul(this);
		}
	}

	public final CalculContext calcul() throws RecognitionException {
		CalculContext _localctx = new CalculContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_calcul);
		 ((CalculContext)_localctx).code =  new String(); 
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(32);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==TYPE) {
				{
				{
				setState(27);
				((CalculContext)_localctx).decl = decl();
				 _localctx.code += ((CalculContext)_localctx).decl.code; 
				}
				}
				setState(34);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(38);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(35);
					match(NEWLINE);
					}
					} 
				}
				setState(40);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			}
			setState(46);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << T__3) | (1L << T__4) | (1L << T__5) | (1L << T__7) | (1L << T__8) | (1L << T__9) | (1L << T__15) | (1L << NEWLINE) | (1L << ENTIER) | (1L << IDENTIFIANT))) != 0)) {
				{
				{
				setState(41);
				((CalculContext)_localctx).instruction = instruction();
				 _localctx.code += ((CalculContext)_localctx).instruction.code; 
				}
				}
				setState(48);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			 _localctx.code += "HALT\n"; 
			}
			_ctx.stop = _input.LT(-1);
			System.out.print(_localctx.code);
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InstructionContext extends ParserRuleContext {
		public String code;
		public ExpressionContext expression;
		public AssignationContext assignation;
		public Token IDENTIFIANT;
		public ConditionContext condition;
		public InstructionContext instruction;
		public BlocContext bloc;
		public AssignationContext init;
		public ConditionContext c;
		public AssignationContext incr;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public FinInstructionContext finInstruction() {
			return getRuleContext(FinInstructionContext.class,0);
		}
		public List<AssignationContext> assignation() {
			return getRuleContexts(AssignationContext.class);
		}
		public AssignationContext assignation(int i) {
			return getRuleContext(AssignationContext.class,i);
		}
		public TerminalNode IDENTIFIANT() { return getToken(CalculetteParser.IDENTIFIANT, 0); }
		public ConditionContext condition() {
			return getRuleContext(ConditionContext.class,0);
		}
		public List<InstructionContext> instruction() {
			return getRuleContexts(InstructionContext.class);
		}
		public InstructionContext instruction(int i) {
			return getRuleContext(InstructionContext.class,i);
		}
		public List<BlocContext> bloc() {
			return getRuleContexts(BlocContext.class);
		}
		public BlocContext bloc(int i) {
			return getRuleContext(BlocContext.class,i);
		}
		public InstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_instruction; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterInstruction(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitInstruction(this);
		}
	}

	public final InstructionContext instruction() throws RecognitionException {
		InstructionContext _localctx = new InstructionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_instruction);
		 ((InstructionContext)_localctx).code =  new String();
		int _la;
		try {
			setState(163);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(51);
				((InstructionContext)_localctx).expression = expression(0);
				setState(52);
				finInstruction();
				 
				            ((InstructionContext)_localctx).code =  ((InstructionContext)_localctx).expression.code;
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(55);
				((InstructionContext)_localctx).assignation = assignation();
				setState(56);
				finInstruction();
				 
							((InstructionContext)_localctx).code =  ((InstructionContext)_localctx).assignation.code;
				        
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(59);
				match(T__0);
				setState(60);
				match(T__1);
				setState(61);
				((InstructionContext)_localctx).IDENTIFIANT = match(IDENTIFIANT);
				setState(62);
				match(T__2);
				setState(63);
				finInstruction();

							((InstructionContext)_localctx).code =  "READ\n" + "STOREG " + tableSymboles.getAdresseType((((InstructionContext)_localctx).IDENTIFIANT!=null?((InstructionContext)_localctx).IDENTIFIANT.getText():null)).adresse + "\n";
						
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(66);
				match(T__3);
				setState(67);
				match(T__1);
				setState(68);
				((InstructionContext)_localctx).expression = expression(0);
				setState(69);
				match(T__2);
				setState(70);
				finInstruction();

							((InstructionContext)_localctx).code =  ((InstructionContext)_localctx).expression.code + "WRITE\n" + "POP\n";
						
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(73);
				match(T__4);
				setState(74);
				match(T__1);
				setState(75);
				((InstructionContext)_localctx).condition = condition(0);
				setState(76);
				match(T__2);
				String i="";
				setState(84);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__0:
				case T__1:
				case T__3:
				case T__4:
				case T__5:
				case T__7:
				case T__8:
				case T__9:
				case T__15:
				case NEWLINE:
				case ENTIER:
				case IDENTIFIANT:
					{
					setState(78);
					((InstructionContext)_localctx).instruction = instruction();
					i+=((InstructionContext)_localctx).instruction.code;
					}
					break;
				case T__30:
					{
					setState(81);
					((InstructionContext)_localctx).bloc = bloc();
					i+=((InstructionContext)_localctx).bloc.code;
					}
					break;
				default:
					throw new NoViableAltException(this);
				}

							String debut = getNewLabel();
							String fin = getNewLabel();
							((InstructionContext)_localctx).code =  "LABEL " + debut + "\n" + ((InstructionContext)_localctx).condition.code + "JUMPF " + fin + "\n";
							_localctx.code += i;
							_localctx.code += "JUMP " + debut + "\n" + "LABEL " + fin + "\n";
						
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(88);
				match(T__5);
				setState(89);
				match(T__1);
				setState(90);
				((InstructionContext)_localctx).condition = condition(0);
				setState(91);
				match(T__2);
				String bthen="";String belse="";
				setState(99);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__0:
				case T__1:
				case T__3:
				case T__4:
				case T__5:
				case T__7:
				case T__8:
				case T__9:
				case T__15:
				case NEWLINE:
				case ENTIER:
				case IDENTIFIANT:
					{
					setState(93);
					((InstructionContext)_localctx).instruction = instruction();
					bthen+=((InstructionContext)_localctx).instruction.code;
					}
					break;
				case T__30:
					{
					setState(96);
					((InstructionContext)_localctx).bloc = bloc();
					bthen+=((InstructionContext)_localctx).bloc.code;
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(112);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
				case 1:
					{
					setState(101);
					match(T__6);
					setState(108);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case T__0:
					case T__1:
					case T__3:
					case T__4:
					case T__5:
					case T__7:
					case T__8:
					case T__9:
					case T__15:
					case NEWLINE:
					case ENTIER:
					case IDENTIFIANT:
						{
						setState(102);
						((InstructionContext)_localctx).instruction = instruction();
						belse+=((InstructionContext)_localctx).instruction.code;
						}
						break;
					case T__30:
						{
						setState(105);
						((InstructionContext)_localctx).bloc = bloc();
						belse+=((InstructionContext)_localctx).bloc.code;
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					((InstructionContext)_localctx).code = "ok";
					}
					break;
				}

							String fin = getNewLabel();			
							if(_localctx.code.equals("")){
								((InstructionContext)_localctx).code =  ((InstructionContext)_localctx).condition.code + "JUMPF " + fin + "\n" + bthen + "LABEL " + fin + "\n";					
							}
							else {
								String sinon = getNewLabel();
								((InstructionContext)_localctx).code =  ((InstructionContext)_localctx).condition.code + "JUMPF " + sinon + "\n" + bthen + "JUMP " + fin + "\nLABEL " + sinon + "\n" + belse + "LABEL " + fin + "\n";
							}
						
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(116);
				match(T__7);
				setState(117);
				match(T__1);
				setState(119);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==IDENTIFIANT) {
					{
					setState(118);
					((InstructionContext)_localctx).init = assignation();
					}
				}

				setState(121);
				match(T__8);
				setState(123);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__15) | (1L << T__18) | (1L << T__19) | (1L << T__29) | (1L << ENTIER) | (1L << IDENTIFIANT))) != 0)) {
					{
					setState(122);
					((InstructionContext)_localctx).c = condition(0);
					}
				}

				setState(125);
				match(T__8);
				setState(127);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==IDENTIFIANT) {
					{
					setState(126);
					((InstructionContext)_localctx).incr = assignation();
					}
				}

				setState(129);
				match(T__2);
				String i="";
				setState(137);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__0:
				case T__1:
				case T__3:
				case T__4:
				case T__5:
				case T__7:
				case T__8:
				case T__9:
				case T__15:
				case NEWLINE:
				case ENTIER:
				case IDENTIFIANT:
					{
					setState(131);
					((InstructionContext)_localctx).instruction = instruction();
					i+=((InstructionContext)_localctx).instruction.code;
					}
					break;
				case T__30:
					{
					setState(134);
					((InstructionContext)_localctx).bloc = bloc();
					i+=((InstructionContext)_localctx).bloc.code;
					}
					break;
				default:
					throw new NoViableAltException(this);
				}

							String debut = getNewLabel();
							String fin = getNewLabel();
							((InstructionContext)_localctx).code =  ((InstructionContext)_localctx).init.code + "LABEL " + debut + "\n";
							_localctx.code += ((InstructionContext)_localctx).c.code + "JUMPF " + fin + "\n";
							_localctx.code += i + ((InstructionContext)_localctx).incr.code + "JUMP " + debut + "\n" + "LABEL " + fin + "\n";
						
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(141);
				match(T__9);
				String i="";
				setState(149);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__0:
				case T__1:
				case T__3:
				case T__4:
				case T__5:
				case T__7:
				case T__8:
				case T__9:
				case T__15:
				case NEWLINE:
				case ENTIER:
				case IDENTIFIANT:
					{
					setState(143);
					((InstructionContext)_localctx).instruction = instruction();
					i+=((InstructionContext)_localctx).instruction.code;
					}
					break;
				case T__30:
					{
					setState(146);
					((InstructionContext)_localctx).bloc = bloc();
					i+=((InstructionContext)_localctx).bloc.code;
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(151);
				match(T__10);
				setState(152);
				match(T__1);
				setState(154);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__15) | (1L << T__18) | (1L << T__19) | (1L << T__29) | (1L << ENTIER) | (1L << IDENTIFIANT))) != 0)) {
					{
					setState(153);
					((InstructionContext)_localctx).c = condition(0);
					}
				}

				setState(156);
				match(T__2);
				setState(157);
				finInstruction();

							String debut = getNewLabel();
							((InstructionContext)_localctx).code =  "LABEL " + debut + "\n" + i + ((InstructionContext)_localctx).c.code + "JUMPF " + debut + "\n";
						
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(160);
				finInstruction();

				            ((InstructionContext)_localctx).code =  "";
				        
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FonctionContext extends ParserRuleContext {
		public String code;
		public BlocContext bloc;
		public TerminalNode TYPE() { return getToken(CalculetteParser.TYPE, 0); }
		public TerminalNode IDENTIFIANT() { return getToken(CalculetteParser.IDENTIFIANT, 0); }
		public BlocContext bloc() {
			return getRuleContext(BlocContext.class,0);
		}
		public ParamsContext params() {
			return getRuleContext(ParamsContext.class,0);
		}
		public FonctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fonction; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterFonction(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitFonction(this);
		}
	}

	public final FonctionContext fonction() throws RecognitionException {
		FonctionContext _localctx = new FonctionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_fonction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(165);
			match(TYPE);
			setState(166);
			match(IDENTIFIANT);
			setState(167);
			match(T__1);
			setState(169);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TYPE) {
				{
				setState(168);
				params();
				}
			}

			setState(171);
			match(T__2);
			 
			            // truc à faire par rapport au "type" de la fonction
			        
			setState(173);
			((FonctionContext)_localctx).bloc = bloc();

			            _localctx.code += ((FonctionContext)_localctx).bloc.code;
			        
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParamsContext extends ParserRuleContext {
		public List<TerminalNode> TYPE() { return getTokens(CalculetteParser.TYPE); }
		public TerminalNode TYPE(int i) {
			return getToken(CalculetteParser.TYPE, i);
		}
		public List<TerminalNode> IDENTIFIANT() { return getTokens(CalculetteParser.IDENTIFIANT); }
		public TerminalNode IDENTIFIANT(int i) {
			return getToken(CalculetteParser.IDENTIFIANT, i);
		}
		public ParamsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_params; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterParams(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitParams(this);
		}
	}

	public final ParamsContext params() throws RecognitionException {
		ParamsContext _localctx = new ParamsContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_params);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(176);
			match(TYPE);
			setState(177);
			match(IDENTIFIANT);
			 
			            // code java gérant la déclaration de "la variable" de retour de la fonction
			        
			setState(185);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__11) {
				{
				{
				setState(179);
				match(T__11);
				setState(180);
				match(TYPE);
				setState(181);
				match(IDENTIFIANT);
				 
				                // code java gérant une variable locale (argi)
				            
				}
				}
				setState(187);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArgsContext extends ParserRuleContext {
		public String code;
		public int size;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ArgsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_args; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterArgs(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitArgs(this);
		}
	}

	public final ArgsContext args() throws RecognitionException {
		ArgsContext _localctx = new ArgsContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_args);
		 ((ArgsContext)_localctx).code =  new String(); ((ArgsContext)_localctx).size =  0; 
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(199);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__1) | (1L << T__15) | (1L << ENTIER) | (1L << IDENTIFIANT))) != 0)) {
				{
				setState(188);
				expression(0);
				 
				        // code java pour première expression pour arg
				    
				setState(196);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__11) {
					{
					{
					setState(190);
					match(T__11);
					setState(191);
					expression(0);
					 
					        // code java pour expression suivante pour arg
					    
					}
					}
					setState(198);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public String code;
		public ExpressionContext a;
		public ExpressionContext expression;
		public Token IDENTIFIANT;
		public Token ENTIER;
		public Token op;
		public ExpressionContext b;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode IDENTIFIANT() { return getToken(CalculetteParser.IDENTIFIANT, 0); }
		public ArgsContext args() {
			return getRuleContext(ArgsContext.class,0);
		}
		public TerminalNode ENTIER() { return getToken(CalculetteParser.ENTIER, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitExpression(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(220);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				{
				setState(202);
				match(T__1);
				setState(203);
				((ExpressionContext)_localctx).expression = expression(0);
				setState(204);
				match(T__2);
				((ExpressionContext)_localctx).code =  ((ExpressionContext)_localctx).expression.code;
				}
				break;
			case 2:
				{
				setState(207);
				((ExpressionContext)_localctx).IDENTIFIANT = match(IDENTIFIANT);
				setState(208);
				match(T__1);
				setState(209);
				args();
				setState(210);
				match(T__2);
				  
							((ExpressionContext)_localctx).code =  "CALL " ;
				        
				}
				break;
			case 3:
				{
				setState(213);
				((ExpressionContext)_localctx).ENTIER = match(ENTIER);
				((ExpressionContext)_localctx).code =  "PUSHI " + (((ExpressionContext)_localctx).ENTIER!=null?Integer.valueOf(((ExpressionContext)_localctx).ENTIER.getText()):0) + "\n";
				}
				break;
			case 4:
				{
				setState(215);
				match(T__15);
				setState(216);
				((ExpressionContext)_localctx).ENTIER = match(ENTIER);
				((ExpressionContext)_localctx).code =  "PUSHI " + (((ExpressionContext)_localctx).ENTIER!=null?Integer.valueOf(((ExpressionContext)_localctx).ENTIER.getText()):0)*(-1 ) + "\n";
				}
				break;
			case 5:
				{
				setState(218);
				((ExpressionContext)_localctx).IDENTIFIANT = match(IDENTIFIANT);
				((ExpressionContext)_localctx).code =  "PUSHG " + tableSymboles.getAdresseType((((ExpressionContext)_localctx).IDENTIFIANT!=null?((ExpressionContext)_localctx).IDENTIFIANT.getText():null)).adresse + "\n";
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(234);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(232);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						_localctx.a = _prevctx;
						_localctx.a = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(222);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(223);
						((ExpressionContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__12 || _la==T__13) ) {
							((ExpressionContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(224);
						((ExpressionContext)_localctx).b = ((ExpressionContext)_localctx).expression = expression(7);

						          		switch((((ExpressionContext)_localctx).op!=null?((ExpressionContext)_localctx).op.getText():null)){
						          			case "*":
						          				((ExpressionContext)_localctx).code =  ((ExpressionContext)_localctx).a.code + ((ExpressionContext)_localctx).b.code + "MUL\n";
						          				break;
						          			case "/":
						          				((ExpressionContext)_localctx).code =  ((ExpressionContext)_localctx).a.code + ((ExpressionContext)_localctx).b.code + "DIV\n";
						          				break;
						          		}
						          	
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						_localctx.a = _prevctx;
						_localctx.a = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(227);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(228);
						((ExpressionContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__14 || _la==T__15) ) {
							((ExpressionContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(229);
						((ExpressionContext)_localctx).b = ((ExpressionContext)_localctx).expression = expression(6);

						          		switch((((ExpressionContext)_localctx).op!=null?((ExpressionContext)_localctx).op.getText():null)){
						          			case "+":
						          				((ExpressionContext)_localctx).code =  ((ExpressionContext)_localctx).a.code + ((ExpressionContext)_localctx).b.code + "ADD\n";
						          				break;
						          			case "-":
						          				((ExpressionContext)_localctx).code =  ((ExpressionContext)_localctx).a.code + ((ExpressionContext)_localctx).b.code + "SUB\n";
						          				break;
						          		}
						          	
						}
						break;
					}
					} 
				}
				setState(236);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class FinInstructionContext extends ParserRuleContext {
		public List<TerminalNode> NEWLINE() { return getTokens(CalculetteParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(CalculetteParser.NEWLINE, i);
		}
		public FinInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_finInstruction; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterFinInstruction(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitFinInstruction(this);
		}
	}

	public final FinInstructionContext finInstruction() throws RecognitionException {
		FinInstructionContext _localctx = new FinInstructionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_finInstruction);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(238); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(237);
					_la = _input.LA(1);
					if ( !(_la==T__8 || _la==NEWLINE) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(240); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclContext extends ParserRuleContext {
		public String code;
		public Token TYPE;
		public Token IDENTIFIANT;
		public ExpressionContext expression;
		public TerminalNode TYPE() { return getToken(CalculetteParser.TYPE, 0); }
		public TerminalNode IDENTIFIANT() { return getToken(CalculetteParser.IDENTIFIANT, 0); }
		public FinInstructionContext finInstruction() {
			return getRuleContext(FinInstructionContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public DeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitDecl(this);
		}
	}

	public final DeclContext decl() throws RecognitionException {
		DeclContext _localctx = new DeclContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_decl);
		try {
			setState(254);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(242);
				((DeclContext)_localctx).TYPE = match(TYPE);
				setState(243);
				((DeclContext)_localctx).IDENTIFIANT = match(IDENTIFIANT);
				setState(244);
				finInstruction();

				            ((DeclContext)_localctx).code =  "PUSHI 0\n";
							tableSymboles.putVar((((DeclContext)_localctx).IDENTIFIANT!=null?((DeclContext)_localctx).IDENTIFIANT.getText():null),(((DeclContext)_localctx).TYPE!=null?((DeclContext)_localctx).TYPE.getText():null));
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(247);
				((DeclContext)_localctx).TYPE = match(TYPE);
				setState(248);
				((DeclContext)_localctx).IDENTIFIANT = match(IDENTIFIANT);
				setState(249);
				match(T__16);
				setState(250);
				((DeclContext)_localctx).expression = expression(0);
				setState(251);
				finInstruction();

				            ((DeclContext)_localctx).code =  ((DeclContext)_localctx).expression.code;
							tableSymboles.putVar((((DeclContext)_localctx).IDENTIFIANT!=null?((DeclContext)_localctx).IDENTIFIANT.getText():null),(((DeclContext)_localctx).TYPE!=null?((DeclContext)_localctx).TYPE.getText():null));
				        
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignationContext extends ParserRuleContext {
		public String code;
		public Token IDENTIFIANT;
		public ExpressionContext expression;
		public TerminalNode IDENTIFIANT() { return getToken(CalculetteParser.IDENTIFIANT, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public AssignationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignation; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterAssignation(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitAssignation(this);
		}
	}

	public final AssignationContext assignation() throws RecognitionException {
		AssignationContext _localctx = new AssignationContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_assignation);
		try {
			setState(264);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(256);
				((AssignationContext)_localctx).IDENTIFIANT = match(IDENTIFIANT);
				setState(257);
				match(T__16);
				setState(258);
				((AssignationContext)_localctx).expression = expression(0);
				  
				            ((AssignationContext)_localctx).code =  ((AssignationContext)_localctx).expression.code + "STOREG " + tableSymboles.getAdresseType((((AssignationContext)_localctx).IDENTIFIANT!=null?((AssignationContext)_localctx).IDENTIFIANT.getText():null)).adresse + "\n";
				        
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(261);
				((AssignationContext)_localctx).IDENTIFIANT = match(IDENTIFIANT);
				setState(262);
				match(T__17);

							((AssignationContext)_localctx).code =  "PUSHI 1\nSTOREG " + tableSymboles.getAdresseType((((AssignationContext)_localctx).IDENTIFIANT!=null?((AssignationContext)_localctx).IDENTIFIANT.getText():null)).adresse + "\n";
						
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConditionContext extends ParserRuleContext {
		public String code;
		public ConditionContext c1;
		public ExpressionContext a;
		public ExpressionContext b;
		public ConditionContext condition;
		public ConditionContext c2;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<ConditionContext> condition() {
			return getRuleContexts(ConditionContext.class);
		}
		public ConditionContext condition(int i) {
			return getRuleContext(ConditionContext.class,i);
		}
		public ConditionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_condition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterCondition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitCondition(this);
		}
	}

	public final ConditionContext condition() throws RecognitionException {
		return condition(0);
	}

	private ConditionContext condition(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ConditionContext _localctx = new ConditionContext(_ctx, _parentState);
		ConditionContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_condition, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(305);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				{
				setState(267);
				match(T__18);
				 ((ConditionContext)_localctx).code =  "PUSHI 1\n"; 
				}
				break;
			case 2:
				{
				setState(269);
				match(T__19);
				 ((ConditionContext)_localctx).code =  "PUSHI 0\n"; 
				}
				break;
			case 3:
				{
				setState(271);
				((ConditionContext)_localctx).a = expression(0);
				setState(272);
				match(T__20);
				setState(273);
				((ConditionContext)_localctx).b = expression(0);
				 ((ConditionContext)_localctx).code =  ((ConditionContext)_localctx).a.code + ((ConditionContext)_localctx).b.code + "EQUAL\n"; 
				}
				break;
			case 4:
				{
				setState(276);
				((ConditionContext)_localctx).a = expression(0);
				setState(277);
				_la = _input.LA(1);
				if ( !(_la==T__21 || _la==T__22) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(278);
				((ConditionContext)_localctx).b = expression(0);
				 ((ConditionContext)_localctx).code =  ((ConditionContext)_localctx).a.code + ((ConditionContext)_localctx).b.code + "NEQ\n"; 
				}
				break;
			case 5:
				{
				setState(281);
				((ConditionContext)_localctx).a = expression(0);
				setState(282);
				match(T__23);
				setState(283);
				((ConditionContext)_localctx).b = expression(0);
				 ((ConditionContext)_localctx).code =  ((ConditionContext)_localctx).a.code + ((ConditionContext)_localctx).b.code + "INFEQ\n"; 
				}
				break;
			case 6:
				{
				setState(286);
				((ConditionContext)_localctx).a = expression(0);
				setState(287);
				match(T__24);
				setState(288);
				((ConditionContext)_localctx).b = expression(0);
				 ((ConditionContext)_localctx).code =  ((ConditionContext)_localctx).a.code + ((ConditionContext)_localctx).b.code + "SUPEQ\n"; 
				}
				break;
			case 7:
				{
				setState(291);
				((ConditionContext)_localctx).a = expression(0);
				setState(292);
				match(T__25);
				setState(293);
				((ConditionContext)_localctx).b = expression(0);
				 ((ConditionContext)_localctx).code =  ((ConditionContext)_localctx).a.code + ((ConditionContext)_localctx).b.code + "INF\n"; 
				}
				break;
			case 8:
				{
				setState(296);
				((ConditionContext)_localctx).a = expression(0);
				setState(297);
				match(T__26);
				setState(298);
				((ConditionContext)_localctx).b = expression(0);
				 ((ConditionContext)_localctx).code =  ((ConditionContext)_localctx).a.code + ((ConditionContext)_localctx).b.code + "SUP\n"; 
				}
				break;
			case 9:
				{
				setState(301);
				match(T__29);
				setState(302);
				((ConditionContext)_localctx).condition = condition(1);
				((ConditionContext)_localctx).code =  ((ConditionContext)_localctx).condition.code + "PUSHI -1\nMUL\nPUSHI 1\nADD\n";
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(319);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(317);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
					case 1:
						{
						_localctx = new ConditionContext(_parentctx, _parentState);
						_localctx.c1 = _prevctx;
						_localctx.c1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_condition);
						setState(307);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(308);
						match(T__27);
						setState(309);
						((ConditionContext)_localctx).c2 = ((ConditionContext)_localctx).condition = condition(4);
						 ((ConditionContext)_localctx).code =  ((ConditionContext)_localctx).c1.code + ((ConditionContext)_localctx).c2.code + "MUL\n"; 
						}
						break;
					case 2:
						{
						_localctx = new ConditionContext(_parentctx, _parentState);
						_localctx.c1 = _prevctx;
						_localctx.c1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_condition);
						setState(312);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(313);
						match(T__28);
						setState(314);
						((ConditionContext)_localctx).c2 = ((ConditionContext)_localctx).condition = condition(3);
						 ((ConditionContext)_localctx).code =  ((ConditionContext)_localctx).c1.code + ((ConditionContext)_localctx).c2.code + "ADD\nPUSHI 1\nSUPEQ\n"; 
						}
						break;
					}
					} 
				}
				setState(321);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class BlocContext extends ParserRuleContext {
		public String code;
		public InstructionContext instruction;
		public FinInstructionContext finInstruction() {
			return getRuleContext(FinInstructionContext.class,0);
		}
		public List<InstructionContext> instruction() {
			return getRuleContexts(InstructionContext.class);
		}
		public InstructionContext instruction(int i) {
			return getRuleContext(InstructionContext.class,i);
		}
		public BlocContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bloc; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).enterBloc(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CalculetteListener ) ((CalculetteListener)listener).exitBloc(this);
		}
	}

	public final BlocContext bloc() throws RecognitionException {
		BlocContext _localctx = new BlocContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_bloc);
		 ((BlocContext)_localctx).code =  new String(); 
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(322);
			match(T__30);
			setState(326); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(323);
				((BlocContext)_localctx).instruction = instruction();
				_localctx.code += ((BlocContext)_localctx).instruction.code;
				}
				}
				setState(328); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << T__3) | (1L << T__4) | (1L << T__5) | (1L << T__7) | (1L << T__8) | (1L << T__9) | (1L << T__15) | (1L << NEWLINE) | (1L << ENTIER) | (1L << IDENTIFIANT))) != 0) );
			setState(330);
			match(T__31);
			setState(331);
			finInstruction();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 6:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 10:
			return condition_sempred((ConditionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 6);
		case 1:
			return precpred(_ctx, 5);
		}
		return true;
	}
	private boolean condition_sempred(ConditionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 3);
		case 3:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3*\u0150\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\3\2\3\2\3\2\3\3\3\3\3\3\7\3!\n\3\f\3\16\3$\13\3\3"+
		"\3\7\3\'\n\3\f\3\16\3*\13\3\3\3\3\3\3\3\7\3/\n\3\f\3\16\3\62\13\3\3\3"+
		"\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4"+
		"W\n\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4f\n\4\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\5\4o\n\4\3\4\3\4\5\4s\n\4\3\4\3\4\3\4\3\4\3\4"+
		"\5\4z\n\4\3\4\3\4\5\4~\n\4\3\4\3\4\5\4\u0082\n\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\5\4\u008c\n\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4\u0098"+
		"\n\4\3\4\3\4\3\4\5\4\u009d\n\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4\u00a6\n"+
		"\4\3\5\3\5\3\5\3\5\5\5\u00ac\n\5\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\7\6\u00ba\n\6\f\6\16\6\u00bd\13\6\3\7\3\7\3\7\3\7\3\7\3\7\7"+
		"\7\u00c5\n\7\f\7\16\7\u00c8\13\7\5\7\u00ca\n\7\3\b\3\b\3\b\3\b\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\5\b\u00df\n\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\7\b\u00eb\n\b\f\b\16\b\u00ee\13\b"+
		"\3\t\6\t\u00f1\n\t\r\t\16\t\u00f2\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n"+
		"\3\n\3\n\3\n\5\n\u0101\n\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13"+
		"\u010b\n\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3"+
		"\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f"+
		"\3\f\3\f\3\f\3\f\3\f\3\f\3\f\5\f\u0134\n\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f"+
		"\3\f\3\f\3\f\7\f\u0140\n\f\f\f\16\f\u0143\13\f\3\r\3\r\3\r\3\r\6\r\u0149"+
		"\n\r\r\r\16\r\u014a\3\r\3\r\3\r\3\r\2\4\16\26\16\2\4\6\b\n\f\16\20\22"+
		"\24\26\30\2\6\3\2\17\20\3\2\21\22\4\2\13\13$$\3\2\30\31\2\u0170\2\32\3"+
		"\2\2\2\4\"\3\2\2\2\6\u00a5\3\2\2\2\b\u00a7\3\2\2\2\n\u00b2\3\2\2\2\f\u00c9"+
		"\3\2\2\2\16\u00de\3\2\2\2\20\u00f0\3\2\2\2\22\u0100\3\2\2\2\24\u010a\3"+
		"\2\2\2\26\u0133\3\2\2\2\30\u0144\3\2\2\2\32\33\5\4\3\2\33\34\7\2\2\3\34"+
		"\3\3\2\2\2\35\36\5\22\n\2\36\37\b\3\1\2\37!\3\2\2\2 \35\3\2\2\2!$\3\2"+
		"\2\2\" \3\2\2\2\"#\3\2\2\2#(\3\2\2\2$\"\3\2\2\2%\'\7$\2\2&%\3\2\2\2\'"+
		"*\3\2\2\2(&\3\2\2\2()\3\2\2\2)\60\3\2\2\2*(\3\2\2\2+,\5\6\4\2,-\b\3\1"+
		"\2-/\3\2\2\2.+\3\2\2\2/\62\3\2\2\2\60.\3\2\2\2\60\61\3\2\2\2\61\63\3\2"+
		"\2\2\62\60\3\2\2\2\63\64\b\3\1\2\64\5\3\2\2\2\65\66\5\16\b\2\66\67\5\20"+
		"\t\2\678\b\4\1\28\u00a6\3\2\2\29:\5\24\13\2:;\5\20\t\2;<\b\4\1\2<\u00a6"+
		"\3\2\2\2=>\7\3\2\2>?\7\4\2\2?@\7)\2\2@A\7\5\2\2AB\5\20\t\2BC\b\4\1\2C"+
		"\u00a6\3\2\2\2DE\7\6\2\2EF\7\4\2\2FG\5\16\b\2GH\7\5\2\2HI\5\20\t\2IJ\b"+
		"\4\1\2J\u00a6\3\2\2\2KL\7\7\2\2LM\7\4\2\2MN\5\26\f\2NO\7\5\2\2OV\b\4\1"+
		"\2PQ\5\6\4\2QR\b\4\1\2RW\3\2\2\2ST\5\30\r\2TU\b\4\1\2UW\3\2\2\2VP\3\2"+
		"\2\2VS\3\2\2\2WX\3\2\2\2XY\b\4\1\2Y\u00a6\3\2\2\2Z[\7\b\2\2[\\\7\4\2\2"+
		"\\]\5\26\f\2]^\7\5\2\2^e\b\4\1\2_`\5\6\4\2`a\b\4\1\2af\3\2\2\2bc\5\30"+
		"\r\2cd\b\4\1\2df\3\2\2\2e_\3\2\2\2eb\3\2\2\2fr\3\2\2\2gn\7\t\2\2hi\5\6"+
		"\4\2ij\b\4\1\2jo\3\2\2\2kl\5\30\r\2lm\b\4\1\2mo\3\2\2\2nh\3\2\2\2nk\3"+
		"\2\2\2op\3\2\2\2pq\b\4\1\2qs\3\2\2\2rg\3\2\2\2rs\3\2\2\2st\3\2\2\2tu\b"+
		"\4\1\2u\u00a6\3\2\2\2vw\7\n\2\2wy\7\4\2\2xz\5\24\13\2yx\3\2\2\2yz\3\2"+
		"\2\2z{\3\2\2\2{}\7\13\2\2|~\5\26\f\2}|\3\2\2\2}~\3\2\2\2~\177\3\2\2\2"+
		"\177\u0081\7\13\2\2\u0080\u0082\5\24\13\2\u0081\u0080\3\2\2\2\u0081\u0082"+
		"\3\2\2\2\u0082\u0083\3\2\2\2\u0083\u0084\7\5\2\2\u0084\u008b\b\4\1\2\u0085"+
		"\u0086\5\6\4\2\u0086\u0087\b\4\1\2\u0087\u008c\3\2\2\2\u0088\u0089\5\30"+
		"\r\2\u0089\u008a\b\4\1\2\u008a\u008c\3\2\2\2\u008b\u0085\3\2\2\2\u008b"+
		"\u0088\3\2\2\2\u008c\u008d\3\2\2\2\u008d\u008e\b\4\1\2\u008e\u00a6\3\2"+
		"\2\2\u008f\u0090\7\f\2\2\u0090\u0097\b\4\1\2\u0091\u0092\5\6\4\2\u0092"+
		"\u0093\b\4\1\2\u0093\u0098\3\2\2\2\u0094\u0095\5\30\r\2\u0095\u0096\b"+
		"\4\1\2\u0096\u0098\3\2\2\2\u0097\u0091\3\2\2\2\u0097\u0094\3\2\2\2\u0098"+
		"\u0099\3\2\2\2\u0099\u009a\7\r\2\2\u009a\u009c\7\4\2\2\u009b\u009d\5\26"+
		"\f\2\u009c\u009b\3\2\2\2\u009c\u009d\3\2\2\2\u009d\u009e\3\2\2\2\u009e"+
		"\u009f\7\5\2\2\u009f\u00a0\5\20\t\2\u00a0\u00a1\b\4\1\2\u00a1\u00a6\3"+
		"\2\2\2\u00a2\u00a3\5\20\t\2\u00a3\u00a4\b\4\1\2\u00a4\u00a6\3\2\2\2\u00a5"+
		"\65\3\2\2\2\u00a59\3\2\2\2\u00a5=\3\2\2\2\u00a5D\3\2\2\2\u00a5K\3\2\2"+
		"\2\u00a5Z\3\2\2\2\u00a5v\3\2\2\2\u00a5\u008f\3\2\2\2\u00a5\u00a2\3\2\2"+
		"\2\u00a6\7\3\2\2\2\u00a7\u00a8\7#\2\2\u00a8\u00a9\7)\2\2\u00a9\u00ab\7"+
		"\4\2\2\u00aa\u00ac\5\n\6\2\u00ab\u00aa\3\2\2\2\u00ab\u00ac\3\2\2\2\u00ac"+
		"\u00ad\3\2\2\2\u00ad\u00ae\7\5\2\2\u00ae\u00af\b\5\1\2\u00af\u00b0\5\30"+
		"\r\2\u00b0\u00b1\b\5\1\2\u00b1\t\3\2\2\2\u00b2\u00b3\7#\2\2\u00b3\u00b4"+
		"\7)\2\2\u00b4\u00bb\b\6\1\2\u00b5\u00b6\7\16\2\2\u00b6\u00b7\7#\2\2\u00b7"+
		"\u00b8\7)\2\2\u00b8\u00ba\b\6\1\2\u00b9\u00b5\3\2\2\2\u00ba\u00bd\3\2"+
		"\2\2\u00bb\u00b9\3\2\2\2\u00bb\u00bc\3\2\2\2\u00bc\13\3\2\2\2\u00bd\u00bb"+
		"\3\2\2\2\u00be\u00bf\5\16\b\2\u00bf\u00c6\b\7\1\2\u00c0\u00c1\7\16\2\2"+
		"\u00c1\u00c2\5\16\b\2\u00c2\u00c3\b\7\1\2\u00c3\u00c5\3\2\2\2\u00c4\u00c0"+
		"\3\2\2\2\u00c5\u00c8\3\2\2\2\u00c6\u00c4\3\2\2\2\u00c6\u00c7\3\2\2\2\u00c7"+
		"\u00ca\3\2\2\2\u00c8\u00c6\3\2\2\2\u00c9\u00be\3\2\2\2\u00c9\u00ca\3\2"+
		"\2\2\u00ca\r\3\2\2\2\u00cb\u00cc\b\b\1\2\u00cc\u00cd\7\4\2\2\u00cd\u00ce"+
		"\5\16\b\2\u00ce\u00cf\7\5\2\2\u00cf\u00d0\b\b\1\2\u00d0\u00df\3\2\2\2"+
		"\u00d1\u00d2\7)\2\2\u00d2\u00d3\7\4\2\2\u00d3\u00d4\5\f\7\2\u00d4\u00d5"+
		"\7\5\2\2\u00d5\u00d6\b\b\1\2\u00d6\u00df\3\2\2\2\u00d7\u00d8\7&\2\2\u00d8"+
		"\u00df\b\b\1\2\u00d9\u00da\7\22\2\2\u00da\u00db\7&\2\2\u00db\u00df\b\b"+
		"\1\2\u00dc\u00dd\7)\2\2\u00dd\u00df\b\b\1\2\u00de\u00cb\3\2\2\2\u00de"+
		"\u00d1\3\2\2\2\u00de\u00d7\3\2\2\2\u00de\u00d9\3\2\2\2\u00de\u00dc\3\2"+
		"\2\2\u00df\u00ec\3\2\2\2\u00e0\u00e1\f\b\2\2\u00e1\u00e2\t\2\2\2\u00e2"+
		"\u00e3\5\16\b\t\u00e3\u00e4\b\b\1\2\u00e4\u00eb\3\2\2\2\u00e5\u00e6\f"+
		"\7\2\2\u00e6\u00e7\t\3\2\2\u00e7\u00e8\5\16\b\b\u00e8\u00e9\b\b\1\2\u00e9"+
		"\u00eb\3\2\2\2\u00ea\u00e0\3\2\2\2\u00ea\u00e5\3\2\2\2\u00eb\u00ee\3\2"+
		"\2\2\u00ec\u00ea\3\2\2\2\u00ec\u00ed\3\2\2\2\u00ed\17\3\2\2\2\u00ee\u00ec"+
		"\3\2\2\2\u00ef\u00f1\t\4\2\2\u00f0\u00ef\3\2\2\2\u00f1\u00f2\3\2\2\2\u00f2"+
		"\u00f0\3\2\2\2\u00f2\u00f3\3\2\2\2\u00f3\21\3\2\2\2\u00f4\u00f5\7#\2\2"+
		"\u00f5\u00f6\7)\2\2\u00f6\u00f7\5\20\t\2\u00f7\u00f8\b\n\1\2\u00f8\u0101"+
		"\3\2\2\2\u00f9\u00fa\7#\2\2\u00fa\u00fb\7)\2\2\u00fb\u00fc\7\23\2\2\u00fc"+
		"\u00fd\5\16\b\2\u00fd\u00fe\5\20\t\2\u00fe\u00ff\b\n\1\2\u00ff\u0101\3"+
		"\2\2\2\u0100\u00f4\3\2\2\2\u0100\u00f9\3\2\2\2\u0101\23\3\2\2\2\u0102"+
		"\u0103\7)\2\2\u0103\u0104\7\23\2\2\u0104\u0105\5\16\b\2\u0105\u0106\b"+
		"\13\1\2\u0106\u010b\3\2\2\2\u0107\u0108\7)\2\2\u0108\u0109\7\24\2\2\u0109"+
		"\u010b\b\13\1\2\u010a\u0102\3\2\2\2\u010a\u0107\3\2\2\2\u010b\25\3\2\2"+
		"\2\u010c\u010d\b\f\1\2\u010d\u010e\7\25\2\2\u010e\u0134\b\f\1\2\u010f"+
		"\u0110\7\26\2\2\u0110\u0134\b\f\1\2\u0111\u0112\5\16\b\2\u0112\u0113\7"+
		"\27\2\2\u0113\u0114\5\16\b\2\u0114\u0115\b\f\1\2\u0115\u0134\3\2\2\2\u0116"+
		"\u0117\5\16\b\2\u0117\u0118\t\5\2\2\u0118\u0119\5\16\b\2\u0119\u011a\b"+
		"\f\1\2\u011a\u0134\3\2\2\2\u011b\u011c\5\16\b\2\u011c\u011d\7\32\2\2\u011d"+
		"\u011e\5\16\b\2\u011e\u011f\b\f\1\2\u011f\u0134\3\2\2\2\u0120\u0121\5"+
		"\16\b\2\u0121\u0122\7\33\2\2\u0122\u0123\5\16\b\2\u0123\u0124\b\f\1\2"+
		"\u0124\u0134\3\2\2\2\u0125\u0126\5\16\b\2\u0126\u0127\7\34\2\2\u0127\u0128"+
		"\5\16\b\2\u0128\u0129\b\f\1\2\u0129\u0134\3\2\2\2\u012a\u012b\5\16\b\2"+
		"\u012b\u012c\7\35\2\2\u012c\u012d\5\16\b\2\u012d\u012e\b\f\1\2\u012e\u0134"+
		"\3\2\2\2\u012f\u0130\7 \2\2\u0130\u0131\5\26\f\3\u0131\u0132\b\f\1\2\u0132"+
		"\u0134\3\2\2\2\u0133\u010c\3\2\2\2\u0133\u010f\3\2\2\2\u0133\u0111\3\2"+
		"\2\2\u0133\u0116\3\2\2\2\u0133\u011b\3\2\2\2\u0133\u0120\3\2\2\2\u0133"+
		"\u0125\3\2\2\2\u0133\u012a\3\2\2\2\u0133\u012f\3\2\2\2\u0134\u0141\3\2"+
		"\2\2\u0135\u0136\f\5\2\2\u0136\u0137\7\36\2\2\u0137\u0138\5\26\f\6\u0138"+
		"\u0139\b\f\1\2\u0139\u0140\3\2\2\2\u013a\u013b\f\4\2\2\u013b\u013c\7\37"+
		"\2\2\u013c\u013d\5\26\f\5\u013d\u013e\b\f\1\2\u013e\u0140\3\2\2\2\u013f"+
		"\u0135\3\2\2\2\u013f\u013a\3\2\2\2\u0140\u0143\3\2\2\2\u0141\u013f\3\2"+
		"\2\2\u0141\u0142\3\2\2\2\u0142\27\3\2\2\2\u0143\u0141\3\2\2\2\u0144\u0148"+
		"\7!\2\2\u0145\u0146\5\6\4\2\u0146\u0147\b\r\1\2\u0147\u0149\3\2\2\2\u0148"+
		"\u0145\3\2\2\2\u0149\u014a\3\2\2\2\u014a\u0148\3\2\2\2\u014a\u014b\3\2"+
		"\2\2\u014b\u014c\3\2\2\2\u014c\u014d\7\"\2\2\u014d\u014e\5\20\t\2\u014e"+
		"\31\3\2\2\2\36\"(\60Venry}\u0081\u008b\u0097\u009c\u00a5\u00ab\u00bb\u00c6"+
		"\u00c9\u00de\u00ea\u00ec\u00f2\u0100\u010a\u0133\u013f\u0141\u014a";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}