import jieba
import jieba.posseg as pseg
import queue
import sqlite3

class _telegram_plugin_part_of_speech:
    verb = ['v', 'vd', 'vn']
    norn = ['n', 'nr', 'nz']
    quantifier = ['m']
    
class _telegram_plugin:
    def __init__(self):
        self.reveive_q = queue.Queue()
        # Connect to database
        self.con = sqlite3.connect('action.db', check_same_thread=False)
        #self.cur = self.con.cursor()
        pass

    def cut(self, text):
        words = pseg.cut(text)
        verb = []
        norn = []
        quantifier = []
        for word, flag in words:
            if flag in _telegram_plugin_part_of_speech.verb:
                verb.append(word)
            elif flag in _telegram_plugin_part_of_speech.norn:
                norn.append(word)
            elif flag in _telegram_plugin_part_of_speech.quantifier:
                quantifier.append(word)

        return [verb, norn, quantifier]

    def word_to_action(self, cut_group):
        # When the sentence is not have norn, return.
        if len(cut_group[1]) < 1:
            return False
        
        # When the sentence only have norn, action is get active.
        if len(cut_group[0]) < 1:
            rows = self.con.execute("select Sensor_ID from Action WHERE \
                    Noun='%s'" % (cut_group[1][0])).fetchall()
            print(rows)
            # Can't get action in database.
            if (len(rows) < 1):
                return False
        else:
            # When the sentence have norn and verb, action is get or set active.
            rows = self.con.execute("select Sensor_ID from Action WHERE \
                    Noun='%s' And Verb='%s'" % (cut_group[1][0], cut_group[0][0])).fetchall()
            print(rows)
            # Can't get action in database.
            if (len(rows) < 1):
                return False
        return True
    
if __name__ == '__main__':
    telegram_plugin = _telegram_plugin()
    cut_group = telegram_plugin.cut("設定溫度")
    telegram_plugin.word_to_action(cut_group)
    pass
