USE [TESTPBL2]
GO
/****** Object:  Table [dbo].[FILLQUESTION]    Script Date: 16/12/2020 7:18:42 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[FILLQUESTION](
	[fq_id] [varchar](10) NOT NULL,
	[link] [int] NULL,
	[message] [varchar](50) NULL,
	[answerKey] [varchar](50) NULL,
 CONSTRAINT [PK_FILLQUESTION] PRIMARY KEY CLUSTERED 
(
	[fq_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[MULTIQUESTION]    Script Date: 16/12/2020 7:18:42 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MULTIQUESTION](
	[mq_id] [varchar](10) NOT NULL,
	[mq_content] [varchar](50) NULL,
	[answerKey] [varchar](5) NULL,
	[answerA] [varchar](50) NULL,
	[answerB] [varchar](50) NULL,
	[answerC] [varchar](50) NULL,
	[answerD] [varchar](50) NULL,
 CONSTRAINT [PK_MULTIQUESTION] PRIMARY KEY CLUSTERED 
(
	[mq_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[USERHASWORD]    Script Date: 16/12/2020 7:18:42 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[USERHASWORD](
	[u_id] [varchar](10) NULL,
	[w_id] [varchar](10) NULL,
	[memoryLevel] [int] NULL,
	[lastTimeLW] [int] NULL,
	[wordDiff] [bit] NULL,
	[timeCheckBack] [int] NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[USERLW]    Script Date: 16/12/2020 7:18:42 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[USERLW](
	[u_id] [varchar](10) NOT NULL,
	[username] [varchar](15) NULL,
	[password] [varchar](15) NULL,
	[nickname] [varchar](15) NULL,
	[goal] [int] NULL,
	[exp] [int] NULL,
	[l_id] [varchar](10) NULL,
 CONSTRAINT [PK_USER] PRIMARY KEY CLUSTERED 
(
	[u_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[WORD]    Script Date: 16/12/2020 7:18:42 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[WORD](
	[w_id] [varchar](10) NOT NULL,
	[word] [varchar](10) NULL,
	[meaning] [varchar](50) NULL,
	[pronounciation] [int] NULL,
	[category] [varchar](50) NULL,
	[example] [varchar](100) NULL,
	[w_level] [int] NULL,
 CONSTRAINT [PK_WORD] PRIMARY KEY CLUSTERED 
(
	[w_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[WORDQUESTION]    Script Date: 16/12/2020 7:18:42 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[WORDQUESTION](
	[wq_id] [varchar](10) NOT NULL,
	[w_id] [varchar](10) NULL,
	[fq_id] [varchar](10) NULL,
	[mq_id] [varchar](10) NULL,
 CONSTRAINT [PK_WORDQUESTION_1] PRIMARY KEY CLUSTERED 
(
	[wq_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011001', 1, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'milk')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011002', 2, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'coffee')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011003', 3, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'yes')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011004', 4, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'hi')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011005', 5, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'rice')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011006', 6, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'iced')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011007', 7, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'noodles')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011008', 8, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'hot')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011009', 9, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'water')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011010', 10, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'bye')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011011', 11, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'no')
INSERT [dbo].[FILLQUESTION] ([fq_id], [link], [message], [answerKey]) VALUES (N'FQ00011012', 12, N'Hay dien tu ban vua nghe duoc vao phia ben duoi:', N'thanks')
GO
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011001', N'Dau la "sua" ?', N'd', N'Water', N'Coffee', N'Tea', N'Milk')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011002', N'Dau la "ca phe" ?', N'a', N'Coffee', N'Milk', N'Water', N'Tea')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011003', N'Dau la "Vang!" ?', N'b', N'Thanks!', N'Yes!', N'Hi!', N'No!')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011004', N'Dau la "chao!" ?', N'c', N'No!', N'Thanks!', N'Hi!', N'Goodbye!')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011005', N'Dau la "com" ?', N'a', N'Rice', N'Iced', N'Noodles', N'Soup')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011006', N'Dau la "da (nuoc da)" ?', N'd', N'Soup', N'Noodles', N'Rice', N'Iced')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011007', N'Dau la "mi" ?', N'b', N'Rice', N'Noodles', N'Soup', N'Iced')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011008', N'Dau la "nong" ?', N'c', N'Hat', N'Cold', N'Hot', N'Horn')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011009', N'Dau la "nuoc" ?', N'a', N'Water', N'Tea', N'Milk', N'Coffee')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011010', N'Dau la "tam biet" ?', N'b', N'Hi!', N'bye!', N'Thanks!', N'Yes!')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011011', N'Dau la "khong" ?', N'c', N'Thanks!', N'Goodbye!', N'No!', N'Hi!')
INSERT [dbo].[MULTIQUESTION] ([mq_id], [mq_content], [answerKey], [answerA], [answerB], [answerC], [answerD]) VALUES (N'MQ00011012', N'Dau la "cam on" ?', N'd', N'Goodbye!', N'No!', N'Yes!', N'Thanks!')
GO
INSERT [dbo].[USERHASWORD] ([u_id], [w_id], [memoryLevel], [lastTimeLW], [wordDiff], [timeCheckBack]) VALUES (N'US0001', N'W1008', 1, 1, 0, 0)
INSERT [dbo].[USERHASWORD] ([u_id], [w_id], [memoryLevel], [lastTimeLW], [wordDiff], [timeCheckBack]) VALUES (N'US0001', N'W1009', 1, 1, 0, 0)
INSERT [dbo].[USERHASWORD] ([u_id], [w_id], [memoryLevel], [lastTimeLW], [wordDiff], [timeCheckBack]) VALUES (N'US0001', N'W1010', 1, 1, 0, 0)
INSERT [dbo].[USERHASWORD] ([u_id], [w_id], [memoryLevel], [lastTimeLW], [wordDiff], [timeCheckBack]) VALUES (N'US0001', N'W1011', 1, 1, 0, 0)
INSERT [dbo].[USERHASWORD] ([u_id], [w_id], [memoryLevel], [lastTimeLW], [wordDiff], [timeCheckBack]) VALUES (N'US0001', N'W1012', 1, 1, 0, 0)
GO
INSERT [dbo].[USERLW] ([u_id], [username], [password], [nickname], [goal], [exp], [l_id]) VALUES (N'US0001', N'minhphu', N'1234', N'phuCute', 1500, 10000, N'L0001')
INSERT [dbo].[USERLW] ([u_id], [username], [password], [nickname], [goal], [exp], [l_id]) VALUES (N'US0002', N'phuocthien', N'4321', N'thienGiaoSu', 3000, 20000, N'L0001')
GO
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1001', N'milk', N'sua', 1, N'noun', N'I am allergic to cow''s milk.', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1002', N'coffee', N'ca phe', 2, N'noun', N'We went for coffee at a small cafe in the high street.', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1003', N'yes', N'vang', 3, N'exclamation', N'''Is this your car?'' ''Yes, it is.''', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1004', N'hi', N'chao', 4, N'exclamation', N'Hi guys!', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1005', N'rice', N'com', 5, N'noun', N'The dish is served with rice.', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1006', N'iced', N'da (nuoc da)', 6, N'adjective', N'iced cucumber soup', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1007', N'noodles', N'mi', 7, N'noun', N'chicken noodle soup', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1008', N'hot', N'nong', 8, N'adjective', N'a hot dry summer', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1009', N'water', N'nuoc', 9, N'noun', N'drinking water', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1010', N'bye', N'tam biet', 10, N'exclamation', N'Bye! See you next week.', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1011', N'no', N'khong', 11, N'exclamation', N'Just say yes or no', 1)
INSERT [dbo].[WORD] ([w_id], [word], [meaning], [pronounciation], [category], [example], [w_level]) VALUES (N'W1012', N'thanks', N'cam on', 12, N'exclamation', N'Here''s the change.'' ''Thanks very much.''', 1)
GO
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0001', N'W1001', N'FQ00011001', N'MQ00011001')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0002', N'W1002', N'FQ00011002', N'MQ00011002')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0003', N'W1003', N'FQ00011003', N'MQ00011003')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0004', N'W1004', N'FQ00011004', N'MQ00011004')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0005', N'W1005', N'FQ00011005', N'MQ00011005')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0006', N'W1006', N'FQ00011006', N'MQ00011006')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0007', N'W1007', N'FQ00011007', N'MQ00011007')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0008', N'W1008', N'FQ00011008', N'MQ00011008')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0009', N'W1009', N'FQ00011009', N'MQ00011009')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0010', N'W1010', N'FQ00011010', N'MQ00011010')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0011', N'W1011', N'FQ00011011', N'MQ00011011')
INSERT [dbo].[WORDQUESTION] ([wq_id], [w_id], [fq_id], [mq_id]) VALUES (N'WQ0012', N'W1012', N'FQ00011012', N'MQ00011012')
GO
ALTER TABLE [dbo].[USERHASWORD]  WITH CHECK ADD  CONSTRAINT [FK_USERHASWORD_WORD] FOREIGN KEY([w_id])
REFERENCES [dbo].[WORD] ([w_id])
GO
ALTER TABLE [dbo].[USERHASWORD] CHECK CONSTRAINT [FK_USERHASWORD_WORD]
GO
