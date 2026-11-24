select 
    board.TITLE,
    board.BOARD_ID,
    reply.REPLY_ID,
    reply.WRITER_ID,
    reply.CONTENTS,
    reply.CREATED_DATE
from USED_GOODS_BOARD as board
    inner join USED_GOODS_REPLY as reply
    on board.BOARD_ID = reply.BOARD_ID
where board.CREATED_DATE >= '2022-10-01' and board.CREATED_DATE <= '2022-10-31'
order by reply.CREATED_DATE asc, board.TITLE asc;